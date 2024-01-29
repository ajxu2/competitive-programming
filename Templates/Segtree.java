class Segtree {
    public int n;
    public long[] tree;
    public long cmb(long a, long b) { return Math.min(a, b); }
    public final long id = Long.MAX_VALUE;
    public Segtree(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        tree = new long[this.n << 1];
        Arrays.fill(tree, id);
    }
    public void upd(int i, long x) {
        i += n;
        tree[i] = x; i >>= 1;
        for (; i > 0; i >>= 1) tree[i] = cmb(tree[i << 1], tree[i << 1 ^ 1]);
    }
    public long qry(int l, int r) {
        l += n; r += n;
        long res = id;
        while (l <= r) {
            if ((l & 1) == 1) res = cmb(res, tree[l++]);
            if ((r & 1) == 0) res = cmb(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
}
