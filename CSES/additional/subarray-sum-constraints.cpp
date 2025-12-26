// created: 12-23-2025 Tue 12:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // construct graph where each vertex is a prefix sum
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--;
        adj[u].push_back({v, w}); adj[v].push_back({u, -w});
    }
    V<ll> p(n + 1, INF);
    bool conflict = false;
    auto dfs = [&](auto&& self, int x) -> void {
        for (auto [i, w] : adj[x]) {
            if (p[i] == INF) {
                p[i] = p[x] + w;
                self(self, i);
            } else if (p[i] != p[x] + w) {
                conflict = true;
            }
        }
    };
    for (int i = 0; i < n + 1; i++) {
        if (p[i] == INF) {
            p[i] = 0;
            dfs(dfs, i);
        }
    }
    if (conflict) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << p[i + 1] - p[i] << " \n"[i == n - 1];
    }
    return 0;
}
