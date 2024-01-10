// created: 01-08-2024 Mon 10:21 PM

import java.util.*;
import java.io.*;

public class CountingNumbers {
    static FastIO io = new FastIO();
    static long[] pow9;
    static long solve(long x) {
        // count number of numbers that satisfy condition and 0 <= n <= x
        if (x < 0) return 0;
        if (x == 0) return 1;
        long ans = 1; String s = Long.toString(x);
        for (int i = 1; i < s.length(); i++) ans += pow9[i];
        for (int i = 0; i <= s.length(); i++) {
            // if it first deviates at the i-th digit
            if (i == s.length()) {
                ans++; break;
            }
            int dig = s.charAt(i) - '0';
            if (i == 0) ans += (dig - 1) * pow9[s.length()-1];
            else {
                int prevdig = s.charAt(i-1) - '0';
                if (prevdig < dig) ans += (dig - 1) * pow9[s.length()-1-i];
                else ans += dig * pow9[s.length()-1-i];
                if (dig == prevdig) break;
            }
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        pow9 = new long[20]; pow9[0] = 1;
        for (int i = 1; i < 20; i++) pow9[i] = pow9[i-1] * 9;
        long a = io.nextLong(), b = io.nextLong();
        io.println(solve(b) - solve(a-1));
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
