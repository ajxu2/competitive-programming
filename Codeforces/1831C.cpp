// created: 05-28-2023 Sun 10:10 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

V<V<int>> adj;
V<int> d;

void dfs(int x, int p) {
    for (int i : adj[x]) {
        if (i == p) continue;
        d[i] = d[x] + 1;
        dfs(i, x);
    }
}

void solve() {
    int n; cin >> n;
    adj.clear(); adj.resize(n); d.resize(n);
    V<array<int, 2>> el;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
        el.push_back({u, v});
    }
    d[0] = 0;
    dfs(0, -1);
    V<int> edges(n, -1); // which edge contributes this node?
    for (int i = 0; i < n-1; i++) {
        if (d[el[i][0]] > d[el[i][1]]) edges[el[i][0]] = i;
        else edges[el[i][1]] = i;
    }
    V<int> depend(n-1, -1);
    for (int i = 0; i < n-1; i++) {
        if (d[el[i][0]] > d[el[i][1]]) depend[i] = edges[el[i][1]];
        else depend[i] = edges[el[i][0]];
    }
    V<bool> vis(n-1, false);
    V<int> dp(n-1, -1);
    function<void(int)> dfs2 = [&](int x) {
        if (vis[x]) return;
        vis[x] = true;
        if (depend[x] == -1) {
            dp[x] = 0; return;
        }
        dfs2(depend[x]);
        if (x > depend[x]) dp[x] = dp[depend[x]];
        else dp[x] = dp[depend[x]] + 1;
    };
    for (int i = 0; i < n-1; i++) dfs2(i);
    cout << *max_element(dp.begin(), dp.end()) + 1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
