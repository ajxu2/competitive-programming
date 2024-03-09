class SparseTable {
    int n; State[][] table;
    private int log2(int x) { return 31 - Integer.numberOfLeadingZeros(x); }
    private State cmb(State x, State y) {
        if (x.compareTo(y) < 0) return x;
        else return y;
    }
    public SparseTable(State[] a) {
        n = a.length;
        table = new State[log2(n)+1][n];
        for (int i = 0; i < n; i++) table[0][i] = a[i];
        for (int i = 1; i <= log2(n); i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = cmb(table[i-1][j], table[i-1][j+(1<<i-1)]);
            }
        }
    }
    public State qry(int l, int r) {
        int lg = log2(r - l + 1);
        return cmb(table[lg][l], table[lg][r-(1<<lg)+1]);
    }
}
 
class State {
    int f, s;
    public State(int f, int s) {
        this.f = f; this.s = s;
    }
    public int compareTo(State o) {
        if (f == o.f) return Integer.compare(s, o.s);
        return Integer.compare(f, o.f);
    }
}
