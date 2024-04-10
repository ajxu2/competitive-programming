// created: 04-09-2024 Tue 09:07 AM

import java.util.*;
import java.io.*;

public class RequiredSubstring {
    static FastIO io = new FastIO();
    static final int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(); String s = io.next(); int m = s.length();
        int[][] pi = new int[m][26]; // KMP prefix function when last char is j
        // calculate pi naively because why not LOL
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 26; j++) {
                String tmp = s.substring(0, i) + (char)('A' + j); // length i + 1
                for (int k = 1; k <= i; k++) {
                    if (tmp.substring(0, k).equals(tmp.substring(i + 1 - k))) pi[i][j] = k;
                }
            }
        }
        int[][] dp = new int[n+1][m]; // dp[i][j] = length i and last matches first j
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // transition from dp[i][j] to next
                for (int k = 0; k < 26; k++) {
                    if ('A' + k == s.charAt(j)) {
                        if (j != m - 1) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
                    } else {
                        dp[i+1][pi[j][k]] = (dp[i+1][pi[j][k]] + dp[i][j]) % MOD;
                    }
                }
            }
        }
        long ans = 1;
        for (int i = 0; i < n; i++) ans = ans * 26 % MOD;
        for (int i = 0; i < m; i++) ans = (ans - dp[n][i]) % MOD;
        if (ans < 0) ans += MOD;
        io.println(ans);
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
