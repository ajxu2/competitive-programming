// created: 12-21-2025 Sun 03:21 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> using min_pq = priority_queue<T, V<T>, greater<T>>;

const int INF = 1'000'000'007;

struct Edge {
    int u, v, capacity, cost;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    V<Edge> edges(2 * m); // edges in residual network
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, r, c; cin >> u >> v >> r >> c; u--, v--;
        edges[2 * i] = {u, v, r, c};
        edges[2 * i + 1] = {v, u, 0, -c};
        adj[u].push_back(2 * i); adj[v].push_back(2 * i + 1);
    }
    V<int> p(n, 0); // potential function
    int ans = 0;
    while (k > 0) {
        // find shortest paths using dijkstra
        V<int> dist(n, INF), par_edge(n, -1);
        min_pq<array<int, 3>> pq; // (dist, node, parent)
        pq.push({0, 0, -1});
        while (!pq.empty()) {
            auto [cur_dist, u, par_u] = pq.top();
            pq.pop();
            if (cur_dist >= dist[u])
                continue;
            dist[u] = cur_dist;
            par_edge[u] = par_u;
            for (int edge_idx : adj[u]) {
                auto [_, v, capacity, cost] = edges[edge_idx];
                if (capacity > 0)
                    pq.push({cur_dist + cost + p[u] - p[v], v, edge_idx});
            }
        }
        // update potential function
        for (int i = 0; i < n; i++)
            if (dist[i] != INF)
                p[i] += dist[i];
        // update residual network
        int cur_edge = par_edge[n - 1];
        if (cur_edge == -1) {
            // sink not reachable, but still flow to be pushed
            cout << "-1\n";
            return 0;
        }
        int to_push = k;
        while (cur_edge != -1) {
            Edge e = edges[cur_edge];
            to_push = min(to_push, e.capacity);
            cur_edge = par_edge[e.u];
        }
        cur_edge = par_edge[n - 1];
        while (cur_edge != -1) {
            Edge e = edges[cur_edge];
            ans += to_push * e.cost;
            edges[cur_edge].capacity -= to_push;
            edges[cur_edge ^ 1].capacity += to_push;
            cur_edge = par_edge[e.u];
        }
        k -= to_push;
    }
    cout << ans << '\n';
    return 0;
}
