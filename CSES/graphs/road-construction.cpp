// created: 02-13-2022 Sun 08:54 PM

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
    // find representative of a node with path compression
    int find(int x) {
        stack<int> tmp;
        while (parent[x] != x) {
            tmp.push(x);
            x = parent[x];
        }
        while (!tmp.empty()) {
            parent[tmp.top()] = x;
            tmp.pop();
        }
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
    int n, m;
    cin >> n >> m; 
    DSU a(n+1);
    int ans1 = n, ans2 = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (a.unite(x, y)) ans1--;
        ans2 = max(ans2, a.size(x));
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
