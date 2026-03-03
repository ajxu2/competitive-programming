// created: 02-23-2026 Mon 12:12 AM

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
        adj[u].push_back(v);
    }
    V<bool> vis(n, false);
    int num_visited = 0;
    set<int> nbors;
    auto dfs = [&](this auto self, int u, int threshold) -> void {
        // visit vertices <= threshold
        if (u > threshold || vis[u])
            return;
        vis[u] = true;
        num_visited++;
        nbors.insert(u);
        for (int v : adj[u]) {
            nbors.insert(v);
            self(v, threshold);
        }
    };
    for (int i = 0; i < n; i++) {
        if (i == 0 || nbors.contains(i))
            dfs(i, i);
        if (num_visited == i + 1)
            cout << ssize(nbors) - i - 1;
        else
            cout << -1;
        cout << '\n';
    }
    return 0;
}
