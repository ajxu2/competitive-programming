// created: 12-20-2024 Fri 09:14 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;
void ckmin(ll& a, ll b) {
    if (b < a) a = b;
}

void solve() {
    int N, M, K; cin >> N >> M >> K;
    V<V<int>> a(N, V<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    V<V<V<ll>>> dp(M, V<V<ll>>(N, V<ll>(M, INF))); // dp[horiz. steps][x][y]
    for (int i = 0; i < M; i++) {
        dp[0][0][i] = (ll)i * K + a[0][i];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // right
            if (i < M-1)  {
                for (int k = 0; k < M; k++) {
                    ckmin(dp[i+1][j][(k+1)%M], dp[i][j][k] + a[j][(k+1)%M]);
                }
            }
            // down
            if (j < N-1) {
                ll mn = *min_element(begin(dp[i][j]), end(dp[i][j]));
                for (int k = 0; k < M; k++) {
                    ckmin(dp[i][j+1][(i+k)%M], mn + (ll)k * K + a[j+1][(i+k)%M]);
                }
            }
        }
    }
    cout << *min_element(begin(dp[M-1][N-1]), end(dp[M-1][N-1])) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
