// created: 12-26-2025 Fri 04:37 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;
const int LOGMX = 20;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> coins;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (c == 1)
            coins.push_back(i);
    }
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    // multisource bfs from coins
    V<int> dist_to_coin(n, INF);
    queue<int> bfs;
    for (int i : coins) {
        bfs.push(i);
        dist_to_coin[i] = 0;
    }
    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();
        for (int v : adj[u]) {
            if (dist_to_coin[v] == INF) {
                bfs.push(v);
                dist_to_coin[v] = dist_to_coin[u] + 1;
            }
        }
    }
    // binary lifting
    V<int> par(n, 0), depth(n, 0);
    bfs.push(0);
    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();
        for (int v : adj[u]) {
            if (v != par[u]) {
                bfs.push(v);
                par[v] = u;
                depth[v] = depth[u] + 1;
            }
        }
    }
    V<V<int>> lift(LOGMX, V<int>(n)), lift_dist(LOGMX, V<int>(n));
    lift[0] = par;
    lift_dist[0] = dist_to_coin;
    for (int i = 1; i < LOGMX; i++) {
        for (int j = 0; j < n; j++) {
            int mid = lift[i - 1][j];
            lift[i][j] = lift[i - 1][mid];
            lift_dist[i][j] = min(lift_dist[i - 1][j], lift_dist[i - 1][mid]);
        }
    }
    // compute min dist on path
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (depth[u] < depth[v])
            swap(u, v);
        int diff = depth[u] - depth[v];
        int min_dist = INF;
        int ans = depth[u] + depth[v];
        for (int i = 0; i < LOGMX; i++) {
            if ((diff >> i) & 1) {
                min_dist = min(min_dist, lift_dist[i][u]);
                u = lift[i][u];
            }
        }
        int lca;
        if (u == v) {
            lca = u;
        } else {
            for (int i = LOGMX - 1; i >= 0; i--) {
                if (lift[i][u] != lift[i][v]) {
                    min_dist = min(min_dist, min(lift_dist[i][u], lift_dist[i][v]));
                    u = lift[i][u];
                    v = lift[i][v];
                }
            }
            min_dist = min(min_dist, min(dist_to_coin[u], dist_to_coin[v]));
            lca = par[u];
        }
        min_dist = min(min_dist, dist_to_coin[lca]);
        ans -= 2 * depth[lca];
        ans += 2 * min_dist;
        cout << ans << '\n';
    }
    return 0;
}
