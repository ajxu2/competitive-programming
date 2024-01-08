// created: 01-07-2024 Sun 11:20 PM

import java.util.*;
import java.io.*;

public class CountingTowers {
    static FastIO io = new FastIO();
    static final int MOD = 1_000_000_007, MAXN = 1_000_000;
    public static void main(String[] args) throws IOException {
        // dp1[i] = number of towers with split top, dp2[i] = number with fused top
        long[] dp1 = new long[MAXN+1], dp2 = new long[MAXN+1];
        dp1[1] = 1; dp2[1] = 1;
        for (int i = 2; i <= MAXN; i++) {
            dp1[i] = (dp1[i-1] * 4 + dp2[i-1]) % MOD;
            dp2[i] = (dp1[i-1] + dp2[i-1] * 2) % MOD;
        }
        int t = io.nextInt();
        for (int i = 0; i < t; i++) {
            int n = io.nextInt();
            io.println((dp1[n] + dp2[n]) % MOD);
        }
        io.close();
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
