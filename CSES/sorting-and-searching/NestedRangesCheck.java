// created: 01-05-2024 Fri 11:42 PM

import java.util.*;
import java.io.*;

public class NestedRangesCheck {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        Seg[] s = new Seg[n];
        for (int i = 0; i < n; i++) {
            s[i] = new Seg();
            s[i].f = io.nextInt(); s[i].s = io.nextInt(); s[i].i = i;
        }
        boolean[] ans1 = new boolean[n], ans2 = new boolean[n];
        Arrays.sort(s, new Comparator<Seg>() {
            public int compare(Seg s1, Seg s2) {
                if (s1.f == s2.f) return -Integer.compare(s1.s, s2.s);
                return Integer.compare(s1.f, s2.f);
            }
        });
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (mx >= s[i].s) ans2[s[i].i] = true;
            else mx = s[i].s;
        }
        int mn = Integer.MAX_VALUE;
        for (int i = n-1; i >= 0; i--) {
            if (mn <= s[i].s) ans1[s[i].i] = true;
            else mn = s[i].s;
        }
        for (int i = 0; i < n; i++) {
            io.print(ans1[i] ? 1 : 0);
            io.print(i == n-1 ? "\n" : " ");
        }
        for (int i = 0; i < n; i++) {
            io.print(ans2[i] ? 1 : 0);
            io.print(i == n-1 ? "\n" : " ");
        }
        io.close();
    }
}

class Seg {
    public int f, s, i;
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
