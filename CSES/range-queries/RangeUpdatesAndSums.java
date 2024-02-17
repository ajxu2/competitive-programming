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
    int n;
    long[] tree, lzAdd, lzSet;
    int[] l, r;
    public LazySeg(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        tree = new long[this.n << 1];
        lzAdd = new long[this.n << 1];
        lzSet = new long[this.n << 1];
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
        if (node >= n) {
            if (lzSet[node] != 0) tree[node] = lzSet[node];
            tree[node] += lzAdd[node];
            lzSet[node] = 0; lzAdd[node] = 0;
            return;
        }
        if (lzSet[node] != 0) {
            tree[node] = (r[node] - l[node] + 1) * lzSet[node];
            lzSet[node << 1] = lzSet[node]; lzAdd[node << 1] = 0;
            lzSet[node << 1 ^ 1] = lzSet[node]; lzAdd[node << 1 ^ 1] = 0;
            lzSet[node] = 0;
        }
        tree[node] += (r[node] - l[node] + 1) * lzAdd[node];
        lzAdd[node << 1] += lzAdd[node]; lzAdd[node << 1 ^ 1] += lzAdd[node];
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
    public void updSet(int ll, int rr, long x, int node) {
        push(node);
        if (ll <= l[node] && r[node] <= rr) {
            lzSet[node] = x;
            lzAdd[node] = 0;
            push(node);
            return;
        }
        if (r[node] < ll || rr < l[node]) return;
        updSet(ll, rr, x, node << 1); updSet(ll, rr, x, node << 1 ^ 1);
        pull(node);
    }
    public long qry(int ll, int rr) { return qry(ll, rr, 1); }
    public void updAdd(int ll, int rr, long x) { updAdd(ll, rr, x, 1); }
    public void updSet(int ll, int rr, long x) { updSet(ll, rr, x, 1); }
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
