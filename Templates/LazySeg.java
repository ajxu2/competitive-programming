class LazySeg {
    int n;
    long[] tree, lzAdd;
    int[] l, r;
    public LazySeg(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        tree = new long[this.n << 1];
        lzAdd = new long[this.n << 1];
        l = new int[this.n << 1];
        r = new int[this.n << 1];
        for (int i = 0; i < this.n; i++) {
            l[i + this.n] = i; r[i + this.n] = i;
        }
        for (int i = this.n - 1; i >= 1; i--) {
            l[i] = l[i << 1]; r[i] = r[i << 1 ^ 1];
        }
    }
    public LazySeg(long[] a) {
        this(a.length);
        for (int i = 0; i < a.length; i++) tree[i + n] = a[i];
        for (int i = n - 1; i >= 1; i--) pull(i);
    }
    public void push(int node) {
        tree[node] += (r[node] - l[node] + 1) * lzAdd[node];
        if (node < n) {
            lzAdd[node << 1] += lzAdd[node];
            lzAdd[node << 1 ^ 1] += lzAdd[node];
        }
        lzAdd[node] = 0;
    }
    public void pull(int node) { tree[node] = tree[node << 1] + tree[node << 1 ^ 1]; }
    public long qry(int ll, int rr, int node) {
        push(node);
        if (ll <= l[node] && r[node] <= rr) return tree[node];
        if (r[node] < ll || rr < l[node]) return 0;
        return qry(ll, rr, node << 1) + qry(ll, rr, node << 1 ^ 1);
    }
    public void updAdd(int ll, int rr, long x, int node) {
        push(node);
        if (ll <= l[node] && r[node] <= rr) {
            lzAdd[node] += x;
            push(node);
            return;
        }
        if (r[node] < ll || rr < l[node]) return;
        updAdd(ll, rr, x, node << 1); updAdd(ll, rr, x, node << 1 ^ 1);
        pull(node);
    }
    public long qry(int ll, int rr) { return qry(ll, rr, 1); }
    public void updAdd(int ll, int rr, long x) { updAdd(ll, rr, x, 1); }
}
