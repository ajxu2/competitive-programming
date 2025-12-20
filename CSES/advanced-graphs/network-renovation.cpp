// created: 12-19-2025 Fri 05:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> leaves;
    auto dfs = [&](auto&& self, int x, int p) -> void {
        if (ssize(adj[x]) == 1)
            leaves.push_back(x);
        for (int i : adj[x])
            if (i != p)
                self(self, i, x);
    };
    dfs(dfs, 0, -1);
    int l = ssize(leaves);
    V<array<int, 2>> ans;
    for (int i = 0; i < (l + 1) / 2; i++)
        ans.push_back({leaves[i], leaves[i + l / 2]});
    cout << ssize(ans) << '\n';
    for (auto [u, v] : ans)
        cout << u + 1 << ' ' << v + 1 << '\n';
    return 0;
}
