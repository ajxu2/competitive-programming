// created: 01-22-2026 Thu 01:10 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    V<int> in(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        in[v]++;
    }
    V<int> topo;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        topo.push_back(u);
        q.pop();
        for (int v : adj[u])
            if (--in[v] == 0)
                q.push(v);
    }
    V<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int u = topo[i];
        for (int v : adj[u])
            dp[u] = max(dp[u], dp[v] + 1);
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}
