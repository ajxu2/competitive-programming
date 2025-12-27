// created: 12-26-2025 Fri 09:59 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int LOGMX = 20;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // consider the set of vertices {coins, a, b}
    // and the set of edges in the union of the paths between all pairs
    // every edge gets traversed twice, except the ones a -- b,
    // which are traversed once
    // root the tree at a coin, then just do some bashing
    int n, q; cin >> n >> q;
    V<bool> has_coin(n, false);
    int root = -1;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (c == 1) {
            has_coin[i] = true;
            root = i;
        }
    }
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> par(n, root), depth(n, 0), num_coins(n, 0);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        if (has_coin[u])
            num_coins[u]++;
        for (int v : adj[u]) {
            if (v != p) {
                par[v] = u;
                depth[v] = depth[u] + 1;
                self(self, v, u);
                num_coins[u] += num_coins[v];
            }
        }
    };
    dfs(dfs, root, -1);
    int base_edges = -1;
    for (int i : num_coins)
        if (i > 0)
            base_edges++;
    V<V<int>> lift(LOGMX, V<int>(n));
    lift[0] = par;
    for (int i = 1; i < LOGMX; i++)
        for (int j = 0; j < n; j++)
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
    auto dist_to_important_vertex = [&](int v) {
        // distance to nearest u such that num_coins[u] > 0
        if (num_coins[v] > 0)
            return 0;
        int res = 0;
        for (int i = LOGMX - 1; i >= 0; i--) {
            if (num_coins[lift[i][v]] == 0) {
                res += 1 << i;
                v = lift[i][v];
            }
        }
        return res + 1;
    };
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        int new_u = u, new_v = v;
        // compute LCA
        if (depth[new_u] < depth[new_v])
            swap(new_u, new_v);
        int diff = depth[new_u] - depth[new_v];
        for (int i = 0; i < LOGMX; i++) 
            if ((diff >> i) & 1)
                new_u = lift[i][new_u];
        int lca;
        if (new_u == new_v) {
            lca = new_u;
        } else {
            for (int i = LOGMX - 1; i >= 0; i--) {
                if (lift[i][new_u] != lift[i][new_v]) {
                    new_u = lift[i][new_u];
                    new_v = lift[i][new_v];
                }
            }
            lca = par[new_u];
        }
        int edges = base_edges;
        edges += dist_to_important_vertex(u);
        edges += dist_to_important_vertex(v);
        edges -= dist_to_important_vertex(lca);
        int path_length = depth[u] + depth[v] - 2 * depth[lca];
        cout << 2 * edges - path_length << '\n';
    }
    return 0;
}
