// created: 03-11-2022 Fri 02:44 PM

#include <bits/stdc++.h>
using namespace std;

// yes yes this is definitely an intended solution to be used in the United States of America Computing Olympiad Silver Division

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

struct Edge {
    int a, b, w;
};

int main() {
#ifndef LOCAL
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");
#endif
    int n, m; cin >> n >> m;
    vector<int> a(n);
    bool sorted = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != i+1) sorted = false;
    }
    if (sorted) {
        cout << "-1\n";
        return 0;
    }
    vector<Edge> el(m);
    for (int i = 0; i < m; i++) cin >> el[i].a >> el[i].b >> el[i].w;
    sort(el.begin(), el.end(), [](const Edge& x, const Edge& y){ return x.w < y.w; });
    // binary search!!!!
    int lo = 0, hi = m-1, mid;
    while (lo < hi) {
        mid = (lo+hi+1)/2;
        DSU g(n+1);
        for (int i = m-1; i >= mid; i--) g.unite(el[i].a, el[i].b);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!g.same(i+1, a[i])) ok = false;
        }
        if (ok) lo = mid;
        else hi = mid - 1;
    }
    cout << el[lo].w << "\n";
    return 0;
}
