// created: 03-11-2022 Fri 05:56 PM

#include <bits/stdc++.h>
using namespace std;

vector<long long> dijk(const vector<vector<array<int, 2>>>& adj, int node) {
    vector<long long> dist(adj.size(), 1e18); dist[node] = 0;
    vector<bool> visited(adj.size(), false);
    priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> pq;
    // pq's elements consist of (distance, node)
    pq.push({0, node});
    while (!pq.empty()) {
        long long process = pq.top()[1]; pq.pop();
        if (visited[process]) continue;
        visited[process] = true;
        for (array<int, 2> i : adj[process]) {
            // i = (node, weight to node)
            dist[i[0]] = min(dist[i[0]], dist[process] + i[1]);
            pq.push({dist[i[0]], i[0]});
        }
    }
    return dist;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<array<int, 2>>> adj(n+1); 
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<long long> dist = dijk(adj, 1);
    for (int i = 1; i <= n; i++) cout << dist[i] << " \n"[i == n];
    return 0;
}
