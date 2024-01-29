// created: 01-28-2024 Sun 12:41 PM

import java.util.*;
import java.io.*;

public class CountingHaybales {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO("haybales.in", "haybales.out");
        int n = io.nextInt(), q = io.nextInt();
        LazySeg s = new LazySeg(n);
        for (int i = 0; i < n; i++) s.updAdd(i, i, io.nextInt());
        for (int i = 0; i < q; i++) {
            char t = io.next().charAt(0);
            if (t == 'M') io.println(s.qryMin(io.nextInt() - 1, io.nextInt() - 1));
            else if (t == 'P') s.updAdd(io.nextInt() - 1, io.nextInt() - 1, io.nextInt());
            else io.println(s.qrySum(io.nextInt() - 1, io.nextInt() - 1));
        }
        io.close();
    }
}

class LazySeg {
    int n;
    long[] sumTree, minTree, lzAdd;
    int[] l, r;
    public LazySeg(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        sumTree = new long[this.n << 1];
        minTree = new long[this.n << 1];
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
    public void push(int node) {
        sumTree[node] += (r[node] - l[node] + 1) * lzAdd[node];
        minTree[node] += lzAdd[node];
        if (node < n) {
            lzAdd[node << 1] += lzAdd[node]; lzAdd[node << 1 ^ 1] += lzAdd[node];
        }
        lzAdd[node] = 0;
    }
    public void pull(int node) {
        sumTree[node] = sumTree[node << 1] + sumTree[node << 1 ^ 1];
        minTree[node] = Math.min(minTree[node << 1], minTree[node << 1 ^ 1]);
    }
    public long qrySum(int ll, int rr, int node) {
        push(node);
        if (ll <= l[node] && r[node] <= rr) return sumTree[node];
        if (r[node] < ll || rr < l[node]) return 0;
        return qrySum(ll, rr, node << 1) + qrySum(ll, rr, node << 1 ^ 1);
    }
    public long qryMin(int ll, int rr, int node) {
        push(node);
        if (ll <= l[node] && r[node] <= rr) return minTree[node];
        if (r[node] < ll || rr < l[node]) return (long)1e18;
        return Math.min(qryMin(ll, rr, node << 1), qryMin(ll, rr, node << 1 ^ 1));
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
    public long qrySum(int ll, int rr) { return qrySum(ll, rr, 1); }
    public long qryMin(int ll, int rr) { return qryMin(ll, rr, 1); }
    public void updAdd(int ll, int rr, long x) { updAdd(ll, rr, x, 1); }
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
