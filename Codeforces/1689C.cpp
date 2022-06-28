// created: 06-28-2022 Tue 03:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<int> dp, sz;

void dfs(int v, int par) {
    vector<int> dp1, sz1;
    for (int i : adj[v]) {
        if (i == par) continue;
        dfs(i, v);
        sz[v] += sz[i];
        dp1.push_back(dp[i]);
        sz1.push_back(sz[i]);
    }
    if (dp1.size() == 1) dp[v] = sz1[0]-1;
    else if (dp1.size() == 2) dp[v] = max(sz1[0]-1+dp1[1], sz1[1]-1+dp1[0]);
}

void solve() {
    int n; cin >> n;
    adj = vector<vector<int>>(n+1);
    dp = vector<int>(n+1, 0); sz = vector<int>(n+1, 1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
