// created: 06-18-2022 Sat 10:24 AM

import java.util.*;
import java.io.*;

public class j_1695C {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T-- > 0) solve();
        io.close();
    }
    static void solve() {
        int n = io.nextInt(), m = io.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = io.nextInt();
                if (a[i][j] == -1) a[i][j]++;
            }
        }
        if ((n+m-1)%2 != 0) {
            io.println("NO");
            return;
        }
        int[][] dp1 = new int[n][m], dp2 = new int[n][m];
        dp1[0][0] = a[0][0]; dp2[0][0] = a[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) dp1[i][j] = dp1[i][j-1];
                else if (j == 0) dp1[i][j] = dp1[i-1][j];
                else dp1[i][j] = Math.min(dp1[i-1][j], dp1[i][j-1]);
                dp1[i][j] += a[i][j];
                if (i == 0) dp2[i][j] = dp2[i][j-1];
                else if (j == 0) dp2[i][j] = dp2[i-1][j];
                else dp2[i][j] = Math.max(dp2[i-1][j], dp2[i][j-1]);
                dp2[i][j] += a[i][j];
            }
        }
        int goal = (n+m-1)/2;
        if (dp1[n-1][m-1] <= goal && goal <= dp2[n-1][m-1]) io.println("YES");
        else io.println("NO");
    }
    // credits to usaco.guide team for this template
    static class FastIO extends PrintWriter {
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
}
