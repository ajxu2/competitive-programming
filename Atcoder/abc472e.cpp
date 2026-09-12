// created: 08-22-2026 Sat 07:49 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<short> color(n, 0); // 0 = unvisited, 1 = red, 2 = blue
    V<int> par(n, -1);
    bool found_conflict = false;
    V<int> cycle;
    auto dfs = [&](this auto self, int u) -> void {
        int nxt = 3 - color[u];
        for (int v : adj[u]) {
            if (found_conflict)
                return;
            if (color[v] == 0) {
                color[v] = nxt;
                par[v] = u;
                self(v);
            } else if (color[v] == color[u]) {
                found_conflict = true;
                int cur = u;
                while (cur != v && cur != -1) {
                    cycle.push_back(cur);
                    cur = par[cur];
                }
                cycle.push_back(v);
                return;
            }
        }
    };
    color[0] = 1;
    dfs(0);
    if (found_conflict) {
        cout << ssize(cycle) << '\n';
        for (int i : cycle)
            cout << i + 1 << ' ';
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
