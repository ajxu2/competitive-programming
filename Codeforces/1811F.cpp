// created: 09-15-2023 Fri 05:51 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    if (!all_of(adj.begin(), adj.end(), [](const V<int>& a) { return sz(a) == 2 || sz(a) == 4; })) {
        cout << "NO\n";
        return;
    }
    int cnt4 = count_if(adj.begin(), adj.end(), [](const V<int>& a) { return sz(a) == 4; });
    if ((ll)cnt4 * cnt4 != n) {
        cout << "NO\n";
        return;
    }
    V<bool> vis(n, 0);
    function<void(int)> dfs = [&](int x) {
        for (int i : adj[x]) {
            if (vis[i]) continue;
            vis[i] = 1; dfs(i);
        }
    };
    vis[0] = 1; dfs(0);
    if (!all_of(vis.begin(), vis.end(), [](const bool& a) { return a; })) {
        cout << "NO\n";
        return;
    }
    // count cycle lengths
    for (int i = 0; i < n; i++) {
        if (sz(adj[i]) != 4) continue;
        int x = *find_if(adj[i].begin(), adj[i].end(), [&](const int& a) { return sz(adj[a]) == 2; }), p = i;
        for (int j = 0; j < cnt4-1; j++) {
            if (adj[x][0] == p) p = x, x = adj[x][1];
            else p = x, x = adj[x][0];
        }
        if (x != i) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
