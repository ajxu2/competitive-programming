// created: 02-18-2022 Fri 11:47 PM

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        sz.resize(n);
        fill(sz.begin(), sz.end(), 1);
    }
    // find representative of a node
    int find(int x) {
        while (parent[x] != x) x = parent[x];
        return x;
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

int main() {
    int n, m; cin >> n >> m;
    DSU a(n+1);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        int first;
        if (k != 0) cin >> first;
        for (int i = 1; i < k; i++) {
            int tmp; cin >> tmp;
            a.unite(first, tmp);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a.size(i) << " \n"[i == n];
    }
    return 0;
}
