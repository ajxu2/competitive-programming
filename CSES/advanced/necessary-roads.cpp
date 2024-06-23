// created: 06-22-2024 Sat 08:20 PM

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
    V<int> sum(n, 0), depth(n, 0);
    V<bool> vis(n, false);
    V<array<int, 2>> ans;
    auto dfs = [&](auto&& self, int x, int p) -> void {
        vis[x] = true;
        for (int i : adj[x]) {
            if (i == p) continue;
            if (vis[i]) {
                if (depth[x] > depth[i]) {
                    sum[x]++; sum[i]--;
                }
            } else {
                depth[i] = depth[x] + 1;
                self(self, i, x);
                sum[x] += sum[i];
            }
        }
        if (x != 0 && sum[x] == 0) ans.push_back({x, p});
    };
    dfs(dfs, 0, -1);
    cout << ssize(ans) << '\n';
    for (array<int, 2> i : ans) cout << i[0] + 1 << ' ' << i[1] + 1 << '\n';
    return 0;
}
