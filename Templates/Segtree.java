static class Segtree {
    private long[] tree;
    public int n;
    // the operator used in the segtree (must be associative and commutative)
    public long cmb(long a, long b) { return Math.min(a, b); }
    // the identity of the operator: cmb(id, x) = cmb(x, id) = x
    private final long id = Long.MAX_VALUE;
    // construct segment tree with n pieces of data
    public Segtree(int n) {
        this.n = n;
        tree = new long[2*n];
        Arrays.fill(tree, id);
    }
    // update value at position i to v
    public void upd(int i, long v) {
        i += n; tree[i] = v;
        while (i > 1) {
            i /= 2; tree[i] = cmb(tree[2*i], tree[2*i+1]);
        }
    }
    // query the range [a, b]
    public long qry(int a, int b) {
        long res = id;
        a += n; b += n;
        while (a <= b) {
            if (a % 2 == 1) res = cmb(res, tree[a++]);
            if (b % 2 == 0) res = cmb(res, tree[b--]);
            a /= 2; b /= 2;
        }
        return res;
    }
}
