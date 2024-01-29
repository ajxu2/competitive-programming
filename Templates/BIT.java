class BIT {
    public int n;
    public long[] a, tree;
    public BIT(int n) {
        this.n = n;
        a = new long[n];
        tree = new long[n];
    }
    public void add(int i, long v) {
        a[i] += v;
        for (; i < n; i |= i + 1) tree[i] += v;
    }
    public void upd(int i, long v) { add(i, v - a[i]); }
    public long qry(int i) {
        long res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    public long qry(int i, int j) { return qry(j) - qry(i-1); }
    public int lower_bound(long v) {
        // returns first x st qry(x) >= v
        // or n if no such elements exist
        int res = -1; long sofar = 0;
        for (int i = 30; i >= 0; i--) {
            if (res + (1 << i) >= n) continue;
            if (sofar + tree[res+(1<<i)] < v) {
                res += 1 << i;
                sofar += tree[res];
            }
        }
        return res + 1;
    }
}
