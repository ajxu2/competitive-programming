// created: 12-14-2024 Sat 09:37 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct DijkstraState {
    int dist, cur, par;
    bool operator<(const DijkstraState& o) const { return dist > o.dist; }
};
const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // first, run dijkstra's algorithm and mark the shortest path
    V<int> dists(n, INF);
    V<int> par(n, -1);
    priority_queue<DijkstraState> pq;
    pq.push({0, 0, -1});
    while (!empty(pq)) {
        DijkstraState state = pq.top();
        pq.pop();
        if (state.dist >= dists[state.cur]) continue;
        dists[state.cur] = state.dist;
        par[state.cur] = state.par;
        for (array<int, 2> i : adj[state.cur]) {
            int nx = i[0], nxd = state.dist + i[1];
            if (dists[nx] == INF) pq.push({nxd, nx, state.cur});
        }
    }
    // if no path found, return
    if (dists[n-1] == INF) {
        cout << "-1\n";
        return 0;
    }
    // otherwise, construct the shortest path
    V<int> shortest_path;
    int tmp = n - 1;
    while (tmp != -1) {
        shortest_path.push_back(tmp);
        tmp = par[tmp];
    }
    reverse(begin(shortest_path), end(shortest_path));
    // for each node, mark where the shortest path goes
    V<int> path_markers(n, -1);
    par.assign(n, -1);
    for (int i = 0; i < ssize(shortest_path) - 1; i++) {
        path_markers[shortest_path[i]] = shortest_path[i+1];
        par[shortest_path[i+1]] = shortest_path[i];
    }
    // run dijkstra's again, this time with the "par" variable
    // indicating whether we have deviated from shortest path
    // 0 for not deviated, 1 for deviated
    dists.assign(n, INF);
    V<int> dists2(n, INF); // shortest distance for deviated
    pq.push({0, 0, 0});
    while (!empty(pq)) {
        DijkstraState state = pq.top();
        pq.pop();
        if (state.par == 0) {
            if (state.dist >= dists[state.cur]) continue;
            dists[state.cur] = state.dist;
        } else {
            if (state.dist >= dists2[state.cur]) continue;
            dists2[state.cur] = state.dist;
        }
        for (array<int, 2> i : adj[state.cur]) {
            int nx = i[0], nxd = state.dist + i[1];
            if (state.par == 0 && (nx == path_markers[state.cur] || nx == par[state.cur])) {
                pq.push({nxd, nx, 0});
            } else {
                pq.push({nxd, nx, 1});
            }
        }
    }
    if (dists2[n-1] == INF) cout << "-1\n";
    else cout << dists[n-1] + dists2[n-1] << '\n';
    return 0;
}
