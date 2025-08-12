// created: 08-11-2025 Mon 11:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    V<int> shops(k);
    for (int& i : shops) {
        cin >> i; i--;
    }
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<array<int, 4>> res(n, {-1, -1, -1, -1}); // {dist1, src1, dist2, src2}
    queue<array<int, 3>> bfs; // {dist, src, node}
    for (int i : shops)
        bfs.push({0, i, i});
    while (!bfs.empty()) {
        auto [dist, src, node] = bfs.front();
        bfs.pop();
        if (res[node][1] == src || res[node][3] != -1)
            continue;
        if (res[node][1] == -1) {
            res[node][0] = dist;
            res[node][1] = src;
        } else {
            res[node][2] = dist;
            res[node][3] = src;
        }
        for (int i : adj[node])
            bfs.push({dist + 1, src, i});
    }
    for (int i = 0; i < n; i++) {
        if (res[i][1] == i)
            cout << res[i][2];
        else
            cout << res[i][0];
        cout << ' ';
    }
    cout << '\n';
    return 0;
}
