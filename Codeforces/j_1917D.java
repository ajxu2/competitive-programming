// created: 12-25-2023 Mon 12:59 PM

import java.util.*;
import java.io.*;

public class j_1917D {
    static FastIO io = new FastIO();
    static final int MOD = 998_244_353;
    static void solve() {
        int n = io.nextInt(), k = io.nextInt();
        int[] p = new int[n], q = new int[k];
        for (int i = 0; i < n; i++) p[i] = io.nextInt();
        for (int i = 0; i < k; i++) q[i] = io.nextInt();
        // find internal inversions
        int internal = 0;
        BIT b = new BIT(k);
        for (int i : q) {
            internal += b.qry(i, k-1); internal %= MOD;
            b.add(i, 1);
        }
        long ans = 0;
        BIT[] bb = new BIT[20];
        for (int i = 0; i < 20; i++) bb[i] = new BIT(2*n);
        int[] over = new int[20];
        for (int i : p) {
            ans += internal; ans %= MOD;
            // diff 0
            ans += bb[0].qry(i, 2*n-1) * k; ans %= MOD;
            for (int j = 1; j < Math.min(20, k); j++) {
                // diff +j
                if (i<<j > 2*n-1) break;
                ans += bb[0].qry(i<<j, 2*n-1) * (k-j); ans %= MOD;
            }
            for (int j = 1; j < Math.min(20, k); j++) {
                // diff -j
                if (bb[j].qry(0, 2*n-1) == 0) {
                    ans += (long)(k-j)*(k-j+1)/2 % MOD * over[j]; ans %= MOD;
                    break;
                }
                ans += (bb[j].qry(i, 2*n-1) + over[j]) * (k-j); ans %= MOD;
            }
            boolean flag = false;
            for (int j = 0; j < 20; j++) {
                if (flag || i<<j > 2*n-1) {
                    over[j]++;
                    flag = true;
                }
                else bb[j].add(i<<j, 1);
            }
        }
        io.println(ans);
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
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
        for (; i >= 0; i = (i & i+1) - 1) res += tree[i];
        return res;
    }
    public long qry(int i, int j) { return qry(j) - qry(i-1); }
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
