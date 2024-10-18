// created: 10-17-2024 Thu 03:47 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); radj[v].push_back(u);
    }
    // kosaraju's algorithm
    V<int> topo; topo.reserve(n);
    V<bool> vis(n, false);
    auto dfs1 = [&](auto&& self, int x) -> void {
        vis[x] = true;
        for (int i : adj[x]) {
            if (!vis[i]) self(self, i);
        }
        topo.push_back(x);
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(dfs1, i);
    }
    reverse(begin(topo), end(topo));
    V<int> scc(n, -1);
    int num_scc = 0;
    auto dfs2 = [&](auto&& self, int x) -> void {
        scc[x] = num_scc;
        for (int i : radj[x]) {
            if (scc[i] == -1) self(self, i);
        }
    };
    for (int i : topo) {
        if (scc[i] == -1) {
            dfs2(dfs2, i);
            num_scc++;
        }
    }
    V<V<int>> scc_nodes(num_scc);
    for (int i = 0; i < n; i++) scc_nodes[scc[i]].push_back(i);
    V<pair<int, ll>> dp(num_scc);
    for (int i = num_scc - 1; i >= 0; i--) {
        dp[i] = {0, 0};
        for (int j : scc_nodes[i]) {
            for (int k : adj[j]) dp[i] = max(dp[i], dp[scc[k]]);
        }
        dp[i].first += ssize(scc_nodes[i]);
        for (int j : scc_nodes[i]) dp[i].second -= a[j];
    }
    pair<int, ll> ans = *max_element(begin(dp), end(dp));
    cout << ans.first << ' ' << -ans.second << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
