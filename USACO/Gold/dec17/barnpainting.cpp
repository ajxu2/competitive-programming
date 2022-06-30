// created: 06-29-2022 Wed 02:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<vector<ll>> dp; // dp[i][j] = number of ways to color this subtree if root i has color j
vector<int> req;

void dfs(int v, int par) {
    for (int i : adj[v]) {
        if (i == par) continue;
        dfs(i, v);
    }
    for (int i = 1; i <= 3; i++) {
        if (req[v] != 0 && req[v] != i) {
            dp[v][i] = 0;
            continue;
        }
        for (int j : adj[v]) {
            if (j == par) continue;
            dp[v][i] *= dp[j][i%3+1] + dp[j][(i+1)%3+1];
            dp[v][i] %= 1000000007;
        }
    }
}

int main() {
#ifndef LOCAL
    ifstream cin("barnpainting.in");
    ofstream cout("barnpainting.out");
#endif
    int n, k; cin >> n >> k;
    adj = vector<vector<int>>(n+1);
    dp = vector<vector<ll>>(n+1, vector<ll>(4, 1));
    req = vector<int>(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 0; i < k; i++) {
        int b, c; cin >> b >> c;
        req[b] = c;
    }
    dfs(1, 0);
    cout << (dp[1][1] + dp[1][2] + dp[1][3]) % 1000000007 << "\n";
    return 0;
}
