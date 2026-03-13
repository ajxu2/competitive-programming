// created: 03-02-2026 Mon 07:35 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> deg(n, 0);
    for (int i = 0; i < n; i++)
        deg[i] = ssize(adj[i]);
    int mxd = 0, mxd_vx = -1, cur_cc = 0;
    V<int> cc(n, -1);
    V<int> depth(n, 0);
    auto dfs = [&](this auto self, int u, int p) -> void {
        cc[u] = cur_cc;
        for (int v : adj[u]) {
            if (v == p)
                continue;
            if (deg[v] >= 3) {
                depth[v] = depth[u] + 1;
                if (depth[v] > mxd) {
                    mxd = depth[v];
                    mxd_vx = v;
                }
            }
            if (deg[v] >= 4)
                self(v, u);
        }
    };
    int ans = 1;
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            if (deg[i] >= 3 && deg[j] >= 3)
                ans = 2;
    for (int i = 0; i < n; i++) {
        if (cc[i] == -1 && deg[i] >= 4) {
            mxd = 0;
            dfs(i, -1);
            if (mxd == 0)
                continue;
            int v1 = mxd_vx;
            mxd = 0;
            for (int j : adj[v1]) {
                if (deg[j] >= 4 && cc[j] == cur_cc) {
                    depth[j] = 1;
                    dfs(j, v1);
                }
            }
            ans = max(ans, mxd + 1);
            cur_cc++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--)
        solve();
    return 0;
}
