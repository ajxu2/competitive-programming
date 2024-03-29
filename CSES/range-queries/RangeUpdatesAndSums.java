// created: 01-27-2024 Sat 11:39 PM

import java.util.*;
import java.io.*;

public class RangeUpdatesAndSums {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = io.nextLong();
        LazySeg s = new LazySeg(a);
        for (int i = 0; i < q; i++) {
            int t = io.nextInt();
            if (t == 1) s.updAdd(io.nextInt() - 1, io.nextInt() - 1, io.nextInt());
            else if (t == 2) s.updSet(io.nextInt() - 1, io.nextInt() - 1, io.nextInt());
            else io.println(s.qry(io.nextInt() - 1, io.nextInt() - 1));
        }
        io.close();
    }
}

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
