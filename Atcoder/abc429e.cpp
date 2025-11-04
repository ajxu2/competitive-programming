// created: 10-25-2025 Sat 08:33 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    string s; cin >> s;
    V<bool> safe(n);
    for (int i = 0; i < n; i++)
        safe[i] = s[i] == 'S';
    queue<array<int, 3>> bfs; // (node, dist, src)
    for (int i = 0; i < n; i++) {
        if (safe[i])
            bfs.push({i, 0, i});
    }
    V<array<int, 2>> first_dist(n, array<int, 2>{-1, -1});
    V<array<int, 2>> second_dist(n, array<int, 2>{-1, -1});
    while (!bfs.empty()) {
        auto [node, dist, src] = bfs.front();
        bfs.pop();
        if (first_dist[node][1] == -1)
            first_dist[node] = {dist, src};
        else if (first_dist[node][1] != src && second_dist[node][1] == -1)
            second_dist[node] = {dist, src};
        else
            continue;
        for (int i : adj[node]) {
            bfs.push({i, dist + 1, src});
        }
    }
    for (int i = 0; i < n; i++) {
        if (!safe[i])
            cout << first_dist[i][0] + second_dist[i][0] << '\n';
    }
    return 0;
}
