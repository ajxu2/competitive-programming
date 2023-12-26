// created: 12-24-2023 Sun 10:07 AM

import java.util.*;
import java.io.*;

public class j_1917E {
    static FastIO io = new FastIO();
    static boolean[][] gen(int n, int k) {
        // for even k
        boolean[][] res = new boolean[n][n];
        // fill up the first k/n rows
        for (int i = 0; i < k/n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = true;
            }
        }
        int st = k / n, rem = k % n;
        // if rem = 2, go back
        if (rem == 2) {
            st--; rem += n;
            for (int i = 0; i < n; i++) res[st][i] = false;
        }
        if (rem % 4 == 0) {
            for (int i = 0; i < rem/4; i++) {
                int x = i / (n/2) * 2, y = i % (n/2) * 2;
                for (int dx = 0; dx <= 1; dx++) {
                    for (int dy = 0; dy <= 1; dy++) {
                        res[st+x+dx][y+dy] = true;
                    }
                }
            }
        } else {
            for (int i = 0; i < rem/2; i++) {
                res[st+i][i] = true;
                res[st+i][(i+1)%(rem/2)] = true;
            }
        }
        return res;
    }
    static void solve() {
        int n = io.nextInt(), k = io.nextInt();
        if (k % 2 == 1) {
            io.println("No");
            return;
        }
        if (k == 2 || k == n * n - 2) {
            if (n == 2) io.println("Yes\n0 1\n1 0");
            else io.println("No");
            return;
        }
        io.println("Yes");
        boolean[][] a;
        if (2 * k < n * n) a = gen(n, k);
        else {
            a = gen(n, n * n - k);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = !a[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j]) io.print("1 ");
                else io.print("0 ");
            }
            io.println();
        }
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T-- > 0) solve();
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
