// created: 12-16-2025 Tue 08:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
    V<V<ll>> dp(n, V<ll>(n + 1, 0)); // dp[l][r] = answer for [l, r)
    V<V<int>> opt(n, V<int>(n + 1, 0)); // opt[l][r] = splitting point for [l, r)
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i + 1] = 0;
        opt[i][i + 1] = i;
        for (int j = i + 2; j <= n; j++) {
            ll res = INF;
            int cur_opt = -1;
            for (int k = max(opt[i][j - 1], i + 1); k <= min(opt[i + 1][j], j - 1); k++) {
                ll cur = dp[i][k] + dp[k][j];
                if (cur < res) {
                    res = cur;
                    cur_opt = k;
                }
            }
            res += p[j] - p[i];
            dp[i][j] = res;
            opt[i][j] = cur_opt;
        }
    }
    cout << dp[0][n] << '\n';
    return 0;
}
