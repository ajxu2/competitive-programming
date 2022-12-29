// created: 12-27-2022 Tue 07:11 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

V<V<int>> adj;
V<bool> vis, act;
V<int> deg;
int cnt;

void dfs(int x) {
    vis[x] = true; cnt++;
    for (int i : adj[x]) if (!vis[i] && act[i]) dfs(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    adj.resize(n); act = V<bool>(n, true); deg = V<int>(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        // remove nodes with degree i
        queue<int> q;
        for (int j = 0; j < n; j++) {
            if (deg[j] == i && act[j]) {
                q.push(j); act[j] = false;
            }
        }
        while (!q.empty()) {
            int process = q.front();
            q.pop();
            for (int j : adj[process]) {
                if (act[j]) {
                    deg[j]--;
                    if (deg[j] == i) {
                        q.push(j); act[j] = false;
                    }
                }
            }
        }
        // if all nodes removed, stop
        bool ok = false;
        for (int j = 0; j < n; j++) ok |= act[j];
        if (!ok) break;
        // find largest CC
        int cc = 0;
        vis = V<bool>(n, false);
        for (int j = 0; j < n; j++) {
            if (vis[j] || !act[j]) continue;
            cnt = 0;
            dfs(j);
            cc = max(cc, cnt);
        }
        ans = max(ans, (ll)cc*(i+1));
    }
    cout << ans << "\n";
    return 0;
}
