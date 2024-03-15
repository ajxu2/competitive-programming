// created: 03-15-2024 Fri 10:11 AM

import java.util.*;
import java.io.*;

public class j_1948D {
    static FastIO io = new FastIO();
    static boolean fake(char x, char y) {
        if (x == '?' || y == '?') return true;
        if (x == y) return true;
        return false;
    }
    static void solve() {
        String s = io.next();
        int n = s.length(), ans = 0;
        for (int test = 1; test <= n / 2; test++) {
            boolean ok = false;
            int cnteq = 0; // count equal
            // strings start from indices 0 and test
            for (int i = 0; i < test; i++) {
                if (fake(s.charAt(i), s.charAt(i+test))) cnteq++;
            }
            if (cnteq == test) ok = true;
            for (int i = 1; i <= n - 2 * test; i++) {
                // i = new start index
                if (fake(s.charAt(i-1), s.charAt(i+test-1))) cnteq--;
                if (fake(s.charAt(i+test-1), s.charAt(i+test+test-1))) cnteq++;
                if (cnteq == test) ok = true;
            }
            if (ok) ans = test;
        }
        io.println(2 * ans);
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
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
