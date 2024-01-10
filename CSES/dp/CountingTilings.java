// created: 01-08-2024 Mon 09:07 PM

import java.util.*;
import java.io.*;

public class CountingTilings {
    static FastIO io = new FastIO();
    static final int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        int[][] dp = new int[m][1<<n]; // 0 = < > u, 1 = n
        boolean[] valid = new boolean[1<<n]; // check if every run of 0s has even length
        Arrays.fill(valid, true);
        for (int i = 0; i < 1<<n; i++) {
            int x = i | (1 << n);
            int cur = 0;
            for (int j = 0; j <= n; j++) {
                if ((x & (1 << j)) != 0) {
                    if (cur % 2 != 0) valid[i] = false;
                    cur = 0;
                } else cur++;
            }
        }
        for (int i = 0; i < 1<<n; i++) if (valid[i]) dp[0][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < 1<<n; j++) {
                // a 1 in this can only come from a 0 in prev
                int mask = ~j & ((1 << n) - 1);
                // enumerate all previous states
                int k = mask;
                do {
                    if (valid[k | j]) dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                    k = (k - 1) & mask;
                } while (k != mask);
            }
        }
        io.println(dp[m-1][0]);
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
