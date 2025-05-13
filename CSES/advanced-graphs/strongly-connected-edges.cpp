// created: 05-18-2024 Sat 03:33 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back({v, i}); adj[v].push_back({u, i});
    }
    V<int> state(m, -1); // states of edges; -1 = unvisited, otherwise starting node
    V<bool> vis(n, false); vis[0] = true;
    auto dfs = [&](auto&& self, int x) -> void {
        for (array<int, 2> i : adj[x]) {
            if (state[i[1]] == -1) state[i[1]] = x;
            if (!vis[i[0]]) {
                vis[i[0]] = true; self(self, i[0]);
            }
        }
    };
    dfs(dfs, 0);
    if (!all_of(begin(vis), end(vis), [](bool i) { return i; })) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    // verify ok
    V<V<int>> radj(n);
    for (int i = 0; i < n; i++) {
        for (array<int, 2> j : adj[i]) if (i == state[j[1]]) radj[j[0]].push_back(i);
    }
    vis.assign(n, false); vis[0] = true;
    auto dfs2 = [&](auto&& self, int x) -> void {
        for (int i : radj[x]) if (!vis[i]) {
            vis[i] = true; self(self, i);
        }
    };
    dfs2(dfs2, 0);
    if (!all_of(begin(vis), end(vis), [](bool i) { return i; })) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < n; i++) for (int j : radj[i]) cout << j + 1 << ' ' << i + 1 << '\n';
    return 0;
}
