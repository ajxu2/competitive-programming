class Segtree {
    public int n;
    public State[] tree;
    public Segtree(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        tree = new State[this.n << 1];
        Arrays.fill(tree, State.id);
    }
    public void upd(int i, State x) {
        i += n;
        tree[i] = x; i >>= 1;
        for (; i > 0; i >>= 1) tree[i] = tree[i << 1].cmb(tree[i << 1 ^ 1]);
    }
    public State qry(int l, int r) {
        l += n; r += n;
        State rl = State.id, rr = State.id;
        while (l <= r) {
            if ((l & 1) == 1) rl = rl.cmb(tree[l++]);
            if ((r & 1) == 0) rr = tree[r--].cmb(rr);
            l >>= 1; r >>= 1;
        }
        return rl.cmb(rr);
    }
}

class State {
    long x;
    public State(long x) { this.x = x; }
    static final State id = new State(0);
    public State cmb(State o) { return new State(x + o.x); }
}
