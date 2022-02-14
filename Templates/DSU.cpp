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
