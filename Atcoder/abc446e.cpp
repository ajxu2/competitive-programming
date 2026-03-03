// created: 02-23-2026 Mon 01:30 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, a, b; cin >> m >> a >> b;
    V<V<int>> adj(m * m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int nxt = (b * i + a * j) % m;
            int u = i * m + j, v = j * m + nxt;
            adj[v].push_back(u);
        }
    }
    V<bool> vis(m * m, false);
    auto dfs = [&](this auto self, int u) -> void {
        if (vis[u])
            return;
        vis[u] = true;
        for (int v : adj[u])
            self(v);
    };
    for (int i = 0; i < m; i++) {
        dfs(i);
        dfs(i * m);
    }
    int ans = m * m;
    for (bool i : vis)
        if (i)
            ans--;
    cout << ans << '\n';
    return 0;
}
