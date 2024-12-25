// created: 12-25-2024 Wed 02:58 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int l, n, m; cin >> l >> n >> m;
    V<int> a(l);
    for (int& i : a) cin >> i;
    V<V<int>> b(n, V<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    V<V<V<bool>>> dp(l+1, V<V<bool>>(n+1, V<bool>(m+1, false)));
    for (int i = l-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            for (int k = m-1; k >= 0; k--) {
                dp[i][j][k] = dp[i][j+1][k] || dp[i][j][k+1];
                if (a[i] == b[j][k] && !dp[i+1][j+1][k+1]) dp[i][j][k] = true;
            }
        }
    }
    cout << (dp[0][0][0] ? 'T' : 'N') << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
