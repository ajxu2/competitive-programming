// created: 06-29-2022 Wed 11:48 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
// dp0[i] = solution for i if we take 0 outgoing edges from i
// dp1[i] = solution for i if we take 1 outgoing edge from i
vector<int> dp0, dp1;

void dfs(int v, int par) {
    // dp0[v] = for all i, sum max(dp0[i], dp1[i])
    // dp1[v] = for all i, max dp0[v] - max(dp0[i], dp1[i]) + dp0[i] + 1
    for (int i : adj[v]) {
        if (i == par) continue;
        dfs(i, v);
        dp0[v] += max(dp0[i], dp1[i]);
    }
    for (int i : adj[v]) {
        if (i == par) continue;
        dp1[v] = max(dp1[v], dp0[v] - max(dp0[i], dp1[i]) + dp0[i] + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    adj = vector<vector<int>>(n+1);
    dp0 = vector<int>(n+1, 0); dp1 = vector<int>(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp0[1], dp1[1]) << "\n";
    return 0;
}
