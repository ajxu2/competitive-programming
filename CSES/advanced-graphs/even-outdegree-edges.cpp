// created: 10-24-2024 Thu 11:15 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // writing down the solution since it's cool :D
    // Solve for each connected component separately.
    // Direct all the edges arbitrarily.
    // Some nodes will have odd outdegree; we need to "fix" these nodes.
    // Note flipping the direction of an edge flips the parity of the outdegrees of both endpoints of the edge.
    // Claim: A connected component is fixable iff there are an even number of nodes with odd outdegree.
    // Proof: An edge flip preserves the parity of the number of nodes with odd outdegree.
    // Conversely, if there are an even number of nodes with odd outdegree, we can pair up the nodes and flip every edge on a path between two nodes in a pair.
    // To optimize this process, just pick paths a -> start -> b, where start is where we start the DFS for this connected component. Then do a prefix sum on tree type thing.
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    V<array<int, 2>> edges(m);
    V<bool> need_flip(n, false);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        if (u > v) swap(u, v);
        adj[u].push_back(v); adj[v].push_back(u);
        edges[i] = {u, v};
        need_flip[u].flip();
    }
    V<bool> vis(n, false);
    V<array<int, 2>> edges_to_flip;
    auto dfs = [&](auto&& self, int x, int p) -> void {
        vis[x] = true;
        for (int i : adj[x]) {
            if (vis[i]) continue;
            self(self, i, x);
            if (need_flip[i]) need_flip[x].flip();
        }
        if (need_flip[x] && p != -1) {
            array<int, 2> tmp = {x, p};
            if (tmp[0] > tmp[1]) swap(tmp[0], tmp[1]);
            edges_to_flip.push_back(tmp);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(dfs, i, -1);
            if (need_flip[i]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    sort(begin(edges_to_flip), end(edges_to_flip));
    for (array<int, 2>& i : edges) {
        if (binary_search(begin(edges_to_flip), end(edges_to_flip), i)) swap(i[0], i[1]);
    }
    for (array<int, 2> i : edges) cout << i[0] + 1 << ' ' << i[1] + 1 << '\n';
    return 0;
}
