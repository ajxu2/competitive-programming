// created: 06-23-2024 Sun 10:14 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll choose2(int x) { return (ll)x * (x - 1) >> 1; }

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> sum(n, 0), depth(n, 0), subt(n, 1);
    V<bool> vis(n, false);
    ll ans = choose2(n);
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
                subt[x] += subt[i];
            }
        }
        if (x != 0 && sum[x] == 0) ans = min(ans, choose2(subt[x]) + choose2(n - subt[x]));
    };
    dfs(dfs, 0, -1);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
