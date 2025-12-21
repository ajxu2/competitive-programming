// created: 12-20-2025 Sat 03:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    // just pie bash
    // each subset of m edges: 2^(# nontrivial CCs) * (n - m)!
    V<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    V<V<V<ll>>> dp(n, V<V<ll>>(n, V<ll>(2, 0)));
    // dp[n][m][isolated] = up to vertex n, sum over all subsets of m edges
    // of 2^(# nontrivial CCs), for last vertex isolated or not
    dp[0][0][1] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][0][1] = 1;
        for (int j = 1; j < n; j++) {
            // last vertex not isolated
            dp[i][j][0] = (dp[i-1][j-1][0] + 2 * dp[i-1][j-1][1]) % MOD;
            // last vertex isolated
            dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
        }
    }
    ll ans = fact[n];
    for (int i = 1; i < n; i++) {
        int mult = i % 2 == 0 ? 1 : -1;
        (ans += mult * fact[n-i] * (dp[n-1][i][0] + dp[n-1][i][1])) %= MOD;
    }
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';
    return 0;
}
