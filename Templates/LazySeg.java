class LazySeg {
    int l, r;
    long v = 0, lzAdd = 0, lzSet = 0;
    LazySeg left, right;
    public LazySeg(int l, int r, long[] a) {
        this.l = l; this.r = r;
        if (l == r) {
            v = a[l];
            return;
        }
        int mid = (l + r) / 2;
        left = new LazySeg(l, mid, a); right = new LazySeg(mid + 1, r, a);
        pull();
    }
    public LazySeg(long[] a) { this(0, a.length - 1, a); }
    public void push() {
        if (l == r) {
            if (lzSet != 0) v = lzSet;
            v += lzAdd;
            lzSet = 0; lzAdd = 0;
            return;
        }
        if (lzSet != 0) {
            v = (r - l + 1) * lzSet;
            left.lzSet = lzSet; left.lzAdd = 0;
            right.lzSet = lzSet; right.lzAdd = 0;
            lzSet = 0;
        }
        v += (r - l + 1) * lzAdd;
        left.lzAdd += lzAdd; right.lzAdd += lzAdd;
        lzAdd = 0;
    }
    public void pull() { v = left.v + right.v; }
    public long qry(int ll, int rr) {
        push();
        if (ll <= l && r <= rr) return v;
        if (r < ll || rr < l) return 0;
        return left.qry(ll, rr) + right.qry(ll, rr);
    }
    public void updAdd(int ll, int rr, long x) {
        if (ll <= l && r <= rr) {
            lzAdd += x;
            push();
            return;
        }
        push();
        if (r < ll || rr < l) return;
        left.updAdd(ll, rr, x); right.updAdd(ll, rr, x);
        pull();
    }
    public void updSet(int ll, int rr, long x) {
        if (ll <= l && r <= rr) {
            lzSet = x;
            lzAdd = 0;
            push();
            return;
        }
        push();
        if (r < ll || rr < l) return;
        left.updSet(ll, rr, x); right.updSet(ll, rr, x);
        pull();
    }
}
