// created: 11-12-2025 Wed 09:47 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

template<class T> using min_pq = priority_queue<T, V<T>, greater<T>>;

const int LOGMX = 20;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> adj(n);
    V<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        edges[i] = {u, v, w};
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // prim's algorithm, maintain parents
    V<int> par(n, -1), par_weight(n), depth(n, 0);
    min_pq<array<int, 3>> pq;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto [w, u, v] = pq.top();
        pq.pop();
        if (par[v] != -1)
            continue;
        par[v] = u;
        par_weight[v] = w;
        if (u != v)
            depth[v] = depth[u] + 1;
        for (auto [nxtv, nxtw] : adj[v])
            pq.push({nxtw, v, nxtv});
    }
    V<V<int>> lift(LOGMX, V<int>(n));
    V<V<int>> lift_w(LOGMX, V<int>(n));
    lift[0] = par;
    lift_w[0] = par_weight;
    for (int i = 1; i < LOGMX; i++) {
        for (int j = 0; j < n; j++) {
            int mid = lift[i-1][j];
            lift[i][j] = lift[i-1][mid];
            lift_w[i][j] = max(lift_w[i-1][j], lift_w[i-1][mid]);
        }
    }
    ll initial_cost = accumulate(begin(par_weight), end(par_weight), 0LL);
    for (auto [u, v, w] : edges) {
        if (depth[u] > depth[v])
            swap(u, v);
        int diff = depth[v] - depth[u];
        // get max weight on path u -- v
        int max_w = 0;
        for (int i = 0; i < LOGMX; i++) {
            if ((diff >> i) & 1) {
                max_w = max(max_w, lift_w[i][v]);
                v = lift[i][v];
            }
        }
        if (u != v) {
            for (int i = LOGMX - 1; i >= 0; i--)  {
                if (lift[i][u] != lift[i][v]) {
                    max_w = max(max_w, max(lift_w[i][u], lift_w[i][v]));
                    u = lift[i][u];
                    v = lift[i][v];
                }
            }
            max_w = max(max_w, max(lift_w[0][u], lift_w[0][v]));
        }
        cout << initial_cost + w - max_w << '\n';
    }
    return 0;
}
