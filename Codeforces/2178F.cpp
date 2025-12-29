// created: 12-29-2025 Mon 12:24 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

void solve() {
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> sz(n, 1), modified_sz(n, 1);
    auto dfs = [&](this auto self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v != p) {
                self(v, u);
                sz[u] += sz[v];
                if (sz[v] % 2 == 1)
                    modified_sz[u] += modified_sz[v];
            }
        }
    };
    dfs(0, -1);
    V<int> cc_sizes;
    for (int i = 1; i < n; i++)
        if (sz[i] % 2 == 0)
            cc_sizes.push_back(modified_sz[i]);
    if (cc_sizes.empty()) {
        cout << "1\n";
        return;
    }
    V<ll> inv(n);
    inv[1] = 1;
    for (int i = 2; i < n; i++)
        inv[i] = (MOD - inv[MOD % i]) * (MOD / i) % MOD;
    ll thing = 1; // (k - 1)! * (size root cc) * (s1s2...sk)^2
    for (int i = 1; i <= ssize(cc_sizes) - 1; i++)
        (thing *= i) %= MOD;
    (thing *= modified_sz[0]) %= MOD;
    for (int i : cc_sizes)
        for (int j = 0; j < 2; j++)
            (thing *= i) %= MOD;
    ll ans = 0;
    for (int i : cc_sizes)
        (ans += thing * inv[i]) %= MOD;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
