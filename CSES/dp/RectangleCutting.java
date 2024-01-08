// created: 01-07-2024 Sun 11:29 PM

import java.util.*;
import java.io.*;

public class RectangleCutting {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int a = io.nextInt(), b = io.nextInt();
        int[][] dp = new int[a+1][b+1]; // dp[i][j] = answer for (i, j)
        for (int i = 1; i <= a; i++) {
            Arrays.fill(dp[i], (int)1e9);
            for (int j = 1; j <= b; j++) {
                if (i == j) dp[i][j] = 0;
                else {
                    for (int k = 1; k < i; k++) dp[i][j] = Math.min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                    for (int k = 1; k < j; k++) dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
            }
        }
        io.println(dp[a][b]);
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
