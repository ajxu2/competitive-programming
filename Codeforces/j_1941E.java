// created: 03-11-2024 Mon 10:00 AM

import java.util.*;
import java.io.*;

public class j_1941E {
    static FastIO io = new FastIO();
    static void solve() {
        int n = io.nextInt(), m = io.nextInt(), k = io.nextInt(), d = io.nextInt();
        long[] costs = new long[n];
        for (int i = 0; i < n; i++) {
            int[] a = new int[m];
            for (int j = 0; j < m; j++) a[j] = io.nextInt();
            Segtree seg = new Segtree(m); seg.upd(0, 1);
            for (int j = 1; j < m; j++) {
                long cur = seg.qry(Math.max(j - d - 1, 0), j - 1) + a[j] + 1;
                //io.println(i + " " + j + " " + cur);
                seg.upd(j, cur);
            }
            costs[i] = seg.qry(m-1, m-1);
        }
        for (int i = 1; i < n; i++) costs[i] += costs[i-1];
        long ans = costs[k-1];
        for (int i = k; i < n; i++) ans = Math.min(ans, costs[i] - costs[i-k]);
        io.println(ans);
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
        io.close();
    }
}

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

// credits to usaco.guide team for this template
class FastIO extends PrintWriter {
    private InputStream stream;
    private byte[] buf = new byte[1<<16];
    private int curChar, numChars;
    // standard input
    public FastIO() { this(System.in,System.out); }
    public FastIO(InputStream i, OutputStream o) {
        super(o);
        stream = i;
    }
    // file input
    public FastIO(String i, String o) throws IOException {
        super(new FileWriter(o));
        stream = new FileInputStream(i);
    }
    // throws InputMismatchException() if previously detected end of file
    private int nextByte() {
        if (numChars == -1) throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars == -1) return -1; // end of file
        }
        return buf[curChar++];
    }
    // to read in entire lines, replace c <= ' '
    // with a function that checks whether c is a line break
    public String next() {
        int c; do { c = nextByte(); } while (c <= ' ');
        StringBuilder res = new StringBuilder();
        do { res.appendCodePoint(c); c = nextByte(); } while (c > ' ');
        return res.toString();
    }
    public int nextInt() {
        int c; do { c = nextByte(); } while (c <= ' ');
        int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = 10*res+c-'0';
            c = nextByte();
        } while (c > ' ');
        return res * sgn;
    }
    public long nextLong() {
        int c; do { c = nextByte(); } while (c <= ' ');
        int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = 10*res+c-'0';
            c = nextByte();
        } while (c > ' ');
        return res * sgn;
    }
    public double nextDouble() { return Double.parseDouble(next()); }
}
