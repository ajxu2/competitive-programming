// created: 02-24-2024 Sat 08:55 PM

import java.util.*;
import java.io.*;

public class RangeQueriesAndCopies {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        List<Segtree> trees = new ArrayList<>();
        trees.add(new Segtree(a));
        while (q --> 0) {
            int t = io.nextInt(), k = io.nextInt() - 1;
            if (t == 1) trees.set(k, trees.get(k).upd(io.nextInt() - 1, io.nextInt()));
            else if (t == 2) io.println(trees.get(k).qry(io.nextInt() - 1, io.nextInt() - 1));
            else trees.add(trees.get(k));
        }
        io.close();
    }
}

class Segtree {
    int l, r;
    long v = 0;
    Segtree lchild = null, rchild = null;
    public long cmb(long x, long y) { return x + y; }
    public Segtree(int l, int r, long[] a) {
        this.l = l; this.r = r;
        if (l == r) {
            v = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        lchild = new Segtree(l, mid, a); rchild = new Segtree(mid + 1, r, a);
        v = cmb(lchild.v, rchild.v);
    }
    public Segtree(long[] a) { this(0, a.length - 1, a); }
    public Segtree(int l, int r) {
        this.l = l; this.r = r;
        // defer assignment of lchild and rchild
    }
    public long qry(int ll, int rr) {
        if (ll <= l && r <= rr) return v;
        if (r < ll || rr < l) return 0;
        return cmb(lchild.qry(ll, rr), rchild.qry(ll, rr));
    }
    public Segtree upd(int i, long x) {
        // returns a new segtree with the updated value
        // note DOES NOT modify original segtree
        Segtree res = new Segtree(l, r);
        if (l == r) {
            res.v = x;
            return res;
        }
        int mid = (l + r) >> 1;
        if (i <= mid) {
            res.lchild = lchild.upd(i, x);
            res.rchild = rchild;
        } else {
            res.lchild = lchild;
            res.rchild = rchild.upd(i, x);
        }
        res.v = cmb(res.lchild.v, res.rchild.v);
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
