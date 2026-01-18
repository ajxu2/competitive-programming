// created: 01-17-2026 Sat 07:18 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, l, s, t; cin >> n >> m >> l >> s >> t;
    V<V<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        adj[u].push_back({v, c});
    }
    V<bool> ans(n, false);
    auto dfs = [&](this auto self, int u, int depth, int w) -> void {
        if (depth == l) {
            if (s <= w && w <= t)
                ans[u] = true;
            return;
        }
        for (auto [v, c] : adj[u])
            self(v, depth + 1, w + c);
    };
    dfs(0, 0, 0);
    for (int i = 0; i < n; i++)
        if (ans[i])
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}
