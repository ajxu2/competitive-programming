// created: 12-21-2023 Thu 03:44 PM

import java.util.*;
import java.io.*;

public class j_1886D {
    static FastIO io = new FastIO();
    static final int MOD = 998_244_353;
    static long pow(long a, int b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    static long inv(long a) { return pow(a, MOD-2); }
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        char[] s = io.next().toCharArray();
        long ans = 1;
        boolean zero = s[0] == '?'; // newjeans <3
        for (int i = 1; i < n-1; i++) {
            if (s[i] == '?') ans = ans * i % MOD;
        }
        io.println(zero ? 0 : ans);
        for (int i = 0; i < m; i++) {
            int j = io.nextInt() - 1;
            char c = io.next().charAt(0);
            if (j == 0) zero = c == '?';
            else if (s[j] != '?' && c == '?') ans = ans * j % MOD;
            else if (s[j] == '?' && c != '?') ans = ans * inv(j) % MOD;
            s[j] = c;
            io.println(zero ? 0 : ans);
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
