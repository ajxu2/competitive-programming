// created: 10-17-2022 Mon 11:32 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;
int sz;

void dfs(int node) {
    vis[node] = true;
    sz++;
    for (int i : adj[node]) if (!vis[i]) dfs(i);
}

int main() {
    int n, m; cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vector<int> cc;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            sz = 0;
            dfs(i);
            cc.push_back(sz);
        }
    }
    bitset<100001> dp;
    dp[0] = 1;
    for (int i : cc) dp |= (dp << i);
    string ans = dp.to_string();
    reverse(ans.begin(), ans.end());
    cout << ans.substr(1, n)  << "\n";
    return 0;
}
