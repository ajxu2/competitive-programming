// created: 07-11-2023 Tue 12:19 PM

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
    int n, m, k; cin >> n >> m >> k;
    V<V<array<int, 2>>> rows(n);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; x1--, y1--, x2--, y2--;
        if (y1 < y2) rows[x1].push_back({y1, -1});
        else rows[x1].push_back({y1-1, 1});
    }
    DSU d(2*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(rows[i])-1; j++) {
            if (rows[i][j][1] == rows[i][j+1][1]) {
                d.unite(rows[i][j][0], rows[i][j+1][0]);
                d.unite(rows[i][j][0] + m, rows[i][j+1][0] + m);
            } else {
                d.unite(rows[i][j][0], rows[i][j+1][0] + m);
                d.unite(rows[i][j][0] + m, rows[i][j+1][0]);
            }
        }
    }
    for (int i = 0; i < m; i++) if (d.same(i, i+m)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}

