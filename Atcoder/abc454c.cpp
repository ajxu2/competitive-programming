// created: 04-18-2026 Sat 09:00 AM

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
    auto dfs = [&](this auto self, int u) -> void {
        if (vis[u])
            return;
        vis[u] = true;
        for (int v : adj[u])
            self(v);
    };
    dfs(0);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += vis[i];
    cout << ans << '\n';
    return 0;
}
