// created: 12-24-2023 Sun 09:05 AM

import java.util.*;
import java.io.*;

public class j_1917C {
    static FastIO io = new FastIO();
    static void solve() {
        int n = io.nextInt(), k = io.nextInt(), d = io.nextInt();
        int[] a = new int[n], v = new int[k];
        for (int i = 0; i < n; i++) a[i] = io.nextInt() - 1;
        for (int i = 0; i < k; i++) v[i] = io.nextInt() - 1;
        int ans = (d - 1) / 2;
        for (int i = 0; i < n; i++) if (a[i] == i) ans++;
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j <= v[i%k]; j++) a[j]++;
            if (d - i - 2 < 0) break;
            int cur = (d - i - 2) / 2;
            for (int j = 0; j < n; j++) if (a[j] == j) cur++;
            ans = Math.max(ans, cur);
        }
        io.println(ans);
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
