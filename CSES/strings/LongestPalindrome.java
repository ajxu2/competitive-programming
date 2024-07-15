// created: 04-07-2024 Sun 09:25 PM

import java.util.*;
import java.io.*;

public class LongestPalindrome {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        String s = io.next();
        StringBuilder whar = new StringBuilder("#");
        for (char i : s.toCharArray()) whar.append(i).append('#');
        HashedString hs1 = new HashedString(whar.toString()), hs2 = new HashedString(whar.reverse().toString());
        int ansidx = -1, anslen = -1;
        for (int i = 0; i < hs1.length(); i++) {
            // palindrome middle is this index
            // find last true such that is palindrome
            int l = 1, r = Math.min(i + 1, hs1.length() - i);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                int ii = hs1.length() - 1 - i;
                if (hs1.substring(i, i + mid) == hs2.substring(ii, ii + mid)) l = mid;
                else r = mid - 1;
            }
            if (l > anslen) {
                anslen = l;
                ansidx = i;
            }
        }
        String ans = whar.reverse().toString().substring(ansidx - anslen + 1, ansidx + anslen);
        whar = new StringBuilder();
        for (char i : ans.toCharArray()) if (i != '#') whar.append(i);
        io.println(whar);
        io.close();
    }
}

class HashedString {
    static final int MOD = 2_000_000_011, p = new Random().nextInt(MOD - 100) + 100;
    static long[] pow = new long[]{1};
    int n; long[] hsh;
    public HashedString(String s) {
        n = s.length();
        hsh = new long[n];
        while (pow.length < n) {
            pow = Arrays.copyOf(pow, pow.length << 1);
            for (int i = pow.length >> 1; i < pow.length; i++) pow[i] = pow[i-1] * p % MOD;
        }
        if (n == 0) return;
        hsh[0] = s.charAt(0);
        for (int i = 1; i < n; i++) hsh[i] = (hsh[i-1] * p + s.charAt(i)) % MOD;
    }
    public int length() { return n; }
    public long substring(int l, int r) {
        if (l == 0) return hsh[r-1];
        long res = (hsh[r-1] - hsh[l-1] * pow[r-l]) % MOD;
        return res < 0 ? res + MOD : res;
    }
    public long substring(int l) { return substring(l, n); }
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
