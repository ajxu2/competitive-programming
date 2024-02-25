// created: 02-21-2024 Wed 12:11 PM

import java.util.*;
import java.io.*;

public class PolynomialQueries {
    static FastIO io = new FastIO();
    static long[] diff(long[] a) {
        // difference array
        long[] res = new long[a.length];
        res[0] = a[0];
        for (int i = 1; i < a.length; i++) res[i] = a[i] - a[i-1];
        return res;
    }
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        long[] dd = diff(diff(a));
        BITrange b = new BITrange(n+2);
        for (int i = 0; i < n; i++) b.add(i, dd[i]);
        while (q --> 0) {
            int t = io.nextInt();
            int l = io.nextInt() - 1, r = io.nextInt() - 1;
            if (t == 1) {
                b.add(l, 1); b.add(r + 1, -(r - l + 2)); b.add(r + 2, r - l + 1);
            } else {
                io.println(b.qry(r) - b.qry(l - 1));
            }
        }
        io.close();
    }
}

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

class BITrange {
    // stores fenwick trees for b, b*i, b*i*i
    BIT b, bi, bii;
    public BITrange(int n) {
        b = new BIT(n);
        bi = new BIT(n);
        bii = new BIT(n);
    }
    public void add(int i, long v) {
        b.add(i, v);
        bi.add(i, v * i);
        bii.add(i, v * i * i);
    }
    public long qry(int i) {
        return (((long)i * i + 3 * i + 2) * b.qry(i) - (2 * i + 3) * bi.qry(i) + bii.qry(i)) / 2;
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

