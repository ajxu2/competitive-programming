// created: 01-07-2026 Wed 09:34 AM

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
    V<int> depth(n, 0);
    auto dfs = [&](this auto self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(v, u);
            }
        }
    };
    dfs(0, -1);
    V<int> freq_depth(n, 0);
    for (int i = 0; i < n; i++)
        freq_depth[depth[i]]++;
    int ans = *max_element(begin(freq_depth), end(freq_depth));
    for (int i = 0; i < n; i++) {
        int children = ssize(adj[i]);
        if (i != 0)
            children--;
        if (children == ans) {
            ans++;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
