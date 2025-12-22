// created: 12-21-2025 Sun 05:22 PM

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
    int n; cin >> n;
    int sz = 2 * n + 2; // number of vertices
    V<Edge> edges; // edges in residual network
    V<V<int>> adj(sz); // 0..n-1 and n..2n-1 nodes, 2n source, 2n+1 sink
    auto add_edge = [&](int u, int v, int r, int c) {
        int i = ssize(edges) / 2;
        edges.push_back({u, v, r, c}); edges.push_back({v, u, 0, -c});
        adj[u].push_back(2 * i); adj[v].push_back(2 * i + 1);
    };
    for (int i = 0; i < n; i++) {
        add_edge(2 * n, i, 1, 0);
        add_edge(i + n, 2 * n + 1, 1, 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            add_edge(i, j + n, 1, c);
        }
    }
    V<int> p(sz, 0); // potential function
    for (;;) {
        // find shortest paths using n^2 dijkstra
        V<int> dist(sz, INF), par_edge(sz, -1);
        V<array<int, 2>> prio(sz, {INF, -1}); // (dist, parent)
        prio[2 * n] = {0, -1};
        for (;;) {
            int min_prio = INF, min_prio_vx = -1;
            for (int i = 0; i < sz; i++) {
                if (dist[i] == INF && prio[i][0] < min_prio) {
                    min_prio = prio[i][0];
                    min_prio_vx = i;
                }
            }
            if (min_prio_vx == -1)
                break;
            dist[min_prio_vx] = min_prio;
            par_edge[min_prio_vx] = prio[min_prio_vx][1];
            for (int edge_idx : adj[min_prio_vx]) {
                auto [u, v, capacity, cost] = edges[edge_idx];
                if (capacity > 0)
                    prio[v] = min(prio[v], {min_prio + cost + p[u] - p[v], edge_idx});
            }
        }
        // update potential function
        for (int i = 0; i < sz; i++)
            if (dist[i] != INF)
                p[i] += dist[i];
        // update residual network
        int cur_edge = par_edge[2 * n + 1];
        if (cur_edge == -1) {
            // sink not reachable
            break;
        }
        int to_push = INF;
        while (cur_edge != -1) {
            Edge e = edges[cur_edge];
            to_push = min(to_push, e.capacity);
            cur_edge = par_edge[e.u];
        }
        cur_edge = par_edge[2 * n + 1];
        while (cur_edge != -1) {
            Edge e = edges[cur_edge];
            edges[cur_edge].capacity -= to_push;
            edges[cur_edge ^ 1].capacity += to_push;
            cur_edge = par_edge[e.u];
        }
    }
    int ans = 0;
    V<array<int, 2>> ans_edges;
    for (auto [u, v, capacity, cost] : edges) {
        if (u < n && n <= v && v < 2 * n && capacity == 0) {
            ans_edges.push_back({u, v - n});
            ans += cost;
        }
    }
    cout << ans << '\n';
    for (auto [u, v] : ans_edges)
        cout << u + 1 << ' ' << v + 1 << '\n';
    return 0;
}
