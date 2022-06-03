static class DSU {
    public int[] parent, sz;
    public DSU(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        sz = new int[n];
        for (int i = 0; i < n; i++) sz[i] = 1;
    }
    // find representative of a node with path compression
    public int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    // find if two nodes are in the same CC
    public boolean same(int x, int y) {
        return (find(x) == find(y));
    }
    // unite two sets by size
    // returns true if any CCs were united
    public boolean unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        // x big y small
        if (sz[x] < sz[y]) {
            int tmp = x; x = y; y = tmp;
        }
        parent[y] = x;
        sz[x] += sz[y];
        return true;
    }
    // get the size of a CC
    public int size(int x) {
        return sz[find(x)];
    }
}
