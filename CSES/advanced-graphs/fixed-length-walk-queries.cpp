// created: 08-11-2025 Mon 11:24 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    // idea: make 2n nodes (node, odd/even)
    // and edges (u, v) turn into (u, odd) -- (v, even) etc
    V<V<int>> adj(2*n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v+n); adj[v+n].push_back(u);
        adj[v].push_back(u+n); adj[u+n].push_back(v);
    }
    V<V<int>> d(n, V<int>(2*n, INF));
    for (int i = 0; i < n; i++) {
        queue<int> bfs;
        d[i][i] = 0;
        bfs.push(i);
        while (!bfs.empty()) {
            int cur = bfs.front();
            bfs.pop();
            for (int j : adj[cur]) {
                if (d[i][j] != INF)
                    continue;
                d[i][j] = d[i][cur] + 1;
                bfs.push(j);
            }
        }
    }
    while (q--) {
        int a, b, x; cin >> a >> b >> x; a--, b--;
        cout << (x >= d[a][b + n * (x % 2)] ? "YES" : "NO") << '\n';
    }
    return 0;
}
