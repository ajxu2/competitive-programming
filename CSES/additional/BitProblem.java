// created: 04-20-2024 Sat 11:25 PM

import java.util.*;
import java.io.*;

public class BitProblem {
    static FastIO io = new FastIO();
    static final int LG = 20;
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        int[] a = new int[1<<LG], vals = new int[n];
        for (int i = 0; i < n; i++) {
            vals[i] = io.nextInt();
            a[vals[i]]++;
        }
        // SOS DP!!!
        int[][] dp = new int[LG][1<<LG], DP = new int[LG][1<<LG];
        for (int i = 0; i < 1<<LG; i++) {
            dp[0][i] = a[i]; DP[0][i] = a[i];
            if ((i & 1) == 1) dp[0][i] += a[i ^ 1];
            else DP[0][i] += a[i ^ 1];
        }
        for (int i = 1; i < LG; i++) {
            for (int j = 0; j < 1<<LG; j++) {
                if ((j & (1 << i)) != 0) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j^(1<<i)];
                    DP[i][j] = DP[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                    DP[i][j] = DP[i-1][j] + DP[i-1][j^(1<<i)];
                }
            }
        }
        StringBuilder out = new StringBuilder();
        for (int i : vals) out.append(dp[LG-1][i]).append(' ').append(DP[LG-1][i]).append(' ').append(n - dp[LG-1][(1<<LG)-1&~i]).append('\n');
        io.print(out);
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
