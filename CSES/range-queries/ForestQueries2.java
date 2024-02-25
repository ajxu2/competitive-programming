// created: 02-18-2024 Sun 12:41 PM

import java.util.*;
import java.io.*;

public class ForestQueries2 {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        boolean[][] a = new boolean[n][n];
        BIT2D b = new BIT2D(n, n);
        for (int i = 0; i < n; i++) {
            String tmp = io.next();
            for (int j = 0; j < n; j++) {
                if (tmp.charAt(j) == '*') {
                    b.add(i, j, 1);
                    a[i][j] = true;
                }
            }
        }
        while (q --> 0) {
            int t = io.nextInt();
            if (t == 1) {
                int i = io.nextInt() - 1, j = io.nextInt() - 1;
                if (a[i][j]) b.add(i, j, -1);
                else b.add(i, j, 1);
                a[i][j] = !a[i][j];
            } else {
                int i1 = io.nextInt() - 1, j1 = io.nextInt() - 1, i2 = io.nextInt() - 1, j2 = io.nextInt() - 1;
                io.println(b.qry(i2, j2) - b.qry(i1-1, j2) - b.qry(i2, j1-1) + b.qry(i1-1, j1-1));
            }
        }
        io.close();
    }
}

class BIT2D {
    public int n, m;
    public long[][] tree;
    public BIT2D(int n, int m) {
        this.n = n; this.m = m;
        tree = new long[n][m];
    }
    public void add(int i, int j, long v) {
        for (int _i = i; _i < n; _i |= _i + 1) {
            for (int _j = j; _j < n; _j |= _j + 1) {
                tree[_i][_j] += v;
            }
        }
    }
    public long qry(int i, int j) {
        long res = 0;
        for (int _i = i; _i >= 0; _i &= _i + 1, _i--) {
            for (int _j = j; _j >= 0; _j &= _j + 1, _j--) {
                res += tree[_i][_j];
            }
        }
        return res;
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

