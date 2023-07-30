// created: 07-29-2023 Sat 11:57 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        sz.resize(n);
        fill(sz.begin(), sz.end(), 1);
    }
    // find representative of a node with path compression
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    // find if two nodes are in the same CC
    bool same(int x, int y) {
        return (find(x) == find(y));
    }
    // unite two sets by size
    // returns true if any CCs were united
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        // x big y small
        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        return true;
    }
    // get the size of a CC
    int size(int node) {
        return sz[find(node)];
    }
};

void solve() {
    int n; cin >> n;
    V<int> a(n+1);
    V<V<int>> adj(n+1);
    DSU d(n+1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; x += i;
        if (x < 0 || x > n) a[i] = 0;
        else a[i] = x;
        d.unite(i, a[i]);
        adj[i].push_back(a[i]); adj[a[i]].push_back(i);
    }
    ll ans = 0;
    if (d.same(0, 1)) {
        // game would end anyways
        V<int> path;
        int x = 1;
        while (x != 0) {
            path.push_back(x); x = a[x];
        }
        ans += (ll)(n-sz(path)) * (2*n+1);
        V<int> subt(n+1);
        function<void(int, int)> dfs = [&](int x, int p) {
            subt[x] = 1;
            for (int i : adj[x]) {
                if (i == p) continue;
                dfs(i, x);
                subt[x] += subt[i];
            }
        };
        dfs(0, -1);
        for (int i : path) ans += d.size(0) + n - subt[i];
    } else {
        // must modify something on path
        V<bool> vis(n+1, 0);
        int x = 1;
        while (!vis[x]) {
            vis[x] = true; x = a[x];
        }
        for (bool i : vis) if (i) ans += d.size(0) + n;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
