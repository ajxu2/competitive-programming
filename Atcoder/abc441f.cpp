// created: 01-17-2026 Sat 08:08 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void chmax(ll& a, ll b) {
    if (b > a)
        a = b;
}

const ll INF = 1e15;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> p(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> v[i];
    V<V<ll>> dp(n + 1, V<ll>(m + 1, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = p[i - 1]; j <= m; j++) {
            chmax(dp[i][j], dp[i - 1][j - p[i - 1]] + v[i - 1]);
        }
    }
    ll max_value = *max_element(begin(dp[n]), end(dp[n]));
    V<V<bool>> good(n + 1, V<bool>(m + 1, false));
    for (int i = 0; i <= m; i++)
        good[n][i] = dp[n][i] == max_value;
    V<int> ans(n, 0);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            if (!good[i][j])
                continue;
            if (dp[i][j] == dp[i - 1][j]) {
                good[i - 1][j] = true;
                ans[i - 1] |= 1;
            }
            if (j >= p[i - 1] && dp[i][j] == dp[i - 1][j - p[i - 1]] + v[i - 1]) {
                good[i - 1][j - p[i - 1]] = true;
                ans[i - 1] |= 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 1)
            cout << 'C';
        else if (ans[i] == 2)
            cout << 'A';
        else
            cout << 'B';
    }
    cout << '\n';
    return 0;
}
