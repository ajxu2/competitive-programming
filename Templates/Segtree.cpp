struct Segtree {
    int n;
    using T = int;
    const T id = INT_MAX;
    T cmb(T i, T j) { return min(i, j); }
    V<T> tree;
    Segtree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        tree.assign(2*n, id);
    }
    void upd(int i, T v) {
        i += n; tree[i] = v;
        while (i > 1) {
            i /= 2; tree[i] = cmb(tree[2*i], tree[2*i+1]);
        }
    }
    T qry(int i, int j) {
        T ra = id, rb = id;
        i += n, j += n;
        while (i <= j) {
            if (i % 2 == 1) ra = cmb(ra, tree[i++]);
            if (j % 2 == 0) rb = cmb(tree[j--], rb);
            i /= 2, j /= 2;
        }
        return cmb(ra, rb);
    }
};
