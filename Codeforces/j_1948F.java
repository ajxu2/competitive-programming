// created: 03-15-2024 Fri 10:35 AM

import java.util.*;
import java.io.*;

public class j_1948F {
    static FastIO io = new FastIO();
    static final int MOD = 998244353, MX = 1000000;
    static final long HALF = 499122177, INVFACT1M = 490058372;
    static long[] fact, ifact;
    static long binom(int x, int y) {
        return fact[x] * ifact[y] % MOD * ifact[x-y] % MOD;
    }
    public static void main(String[] args) throws IOException {
        fact = new long[MX+1]; ifact = new long[MX+1];
        long[] powhalf = new long[MX+1];
        fact[0] = 1;
        for (int i = 1; i <= MX; i++) fact[i] = fact[i-1] * i % MOD;
        ifact[MX] = INVFACT1M;
        for (int i = MX - 1; i >= 0; i--) ifact[i] = ifact[i+1] * (i+1) % MOD;
        powhalf[0] = 1;
        for (int i = 1; i <= MX; i++) powhalf[i] = powhalf[i-1] * HALF % MOD;
        int n = io.nextInt(), q = io.nextInt();
        long[] a = new long[n], b = new long[n];
        int ta = 0, tb = 0;
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt(); ta += a[i];
        }
        for (int i = 0; i < n; i++) {
            b[i] = io.nextInt(); tb += b[i];
        }
        long[] coeffs = new long[tb+1];
        for (int i = 0; i <= tb; i++) coeffs[i] = binom(tb, i);
        PrefixSum pa = new PrefixSum(a), pb = new PrefixSum(b), pc = new PrefixSum(coeffs);
        while (q --> 0) {
            int l = io.nextInt() - 1, r = io.nextInt() - 1;
            int leftgold = 2 * (int)pa.qry(l, r) - ta, rightsilver = tb - (int)pb.qry(l, r);
            int bound = rightsilver - leftgold;
            if (bound < 0) io.print("1 ");
            else if (bound > tb) io.print("0 ");
            else io.print(powhalf[tb] * (pc.qry(bound+1, tb) % MOD) % MOD + " ");
        }
        io.println();
        io.close();
    }
}

class PrefixSum {
    long[] p;
    public PrefixSum(long[] a) {
        p = new long[a.length]; p[0] = a[0];
        for (int i = 1; i < a.length; i++) p[i] = p[i-1] + a[i];
    }
    public long qry(int l, int r) {
        return l == 0 ? p[r] : p[r] - p[l-1];
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
