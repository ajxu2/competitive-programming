// created: 06-22-2024 Sat 10:03 PM

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
    V<int> sum(n, 0), depth(n, 0), curchild(n, -1);
    V<bool> vis(n, false);
    V<int> ans;
    auto dfs = [&](auto&& self, int x, int p) -> void {
        vis[x] = true;
        int cntbridge = 0;
        for (int i : adj[x]) {
            if (i == p) continue;
            if (vis[i]) {
                if (depth[x] > depth[i]) {
                    sum[x]++; sum[curchild[i]]--;
                }
            } else {
                depth[i] = depth[x] + 1;
                curchild[x] = i;
                self(self, i, x);
                sum[x] += sum[i];
                if (sum[i] == 0) cntbridge++;
            }
        }
        curchild[x] = -1;
        if ((p == -1 && cntbridge > 1) || (p != -1 && cntbridge > 0)) ans.push_back(x);
    };
    dfs(dfs, 0, -1);
    cout << ssize(ans) << '\n';
    for (int i = 0; i < ssize(ans); i++) cout << ans[i] + 1 << " \n"[i == ssize(ans) - 1];
    return 0;
}
