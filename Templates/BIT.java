static class BIT {
    private long[] tree;
    public int n;
    // construct BIT with n pieces of data
    public BIT(int n) {
        this.n = n;
        tree = new long[n+1];
    }
    // increase value at position i by v (1-indexed)
    public void add(int i, long v) {
        while (i <= n) {
            tree[i] += v;
            i += i & -i;
        }
    }
    // update value at position i to v (1-indexed)
    public void upd(int i, long v) {
        long d = v - qry(i, i);
        add(i, d);
    }
    // query the sum from [1, a] (1-indexed)
    public long qry(int a) {
        long res = 0;
        while (a > 0) {
            res += tree[a];
            a -= a & -a;
        }
        return res;
    }
    // query the sum from [a, b] (a and b are 1-indexed)
    public long qry(int a, int b) {
        return qry(b) - qry(a-1);
    }
}
