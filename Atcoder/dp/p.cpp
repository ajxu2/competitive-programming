// created: 01-22-2026 Thu 02:19 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<array<ll, 2>> dp(n, {1, 1});
    auto dfs = [&](this auto self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v != p) {
                self(v, u);
                (dp[u][0] *= (dp[v][0] + dp[v][1])) %= MOD;
                (dp[u][1] *= dp[v][0]) %= MOD;
            }
        }
    };
    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
    return 0;
}
