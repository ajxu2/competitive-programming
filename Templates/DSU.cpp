struct DSU {
    V<int> par, sz;
    DSU(int n) {
        par.resize(n);
        iota(begin(par), end(par), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x; sz[x] += sz[y];
    }
    int size(int x) { return sz[find(x)]; }
};

