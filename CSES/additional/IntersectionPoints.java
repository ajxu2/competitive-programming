// created: 04-20-2024 Sat 10:49 PM

import java.util.*;
import java.io.*;

public class IntersectionPoints {
    static FastIO io = new FastIO();
    static Random r = new Random();
    static final int MX = 1_000_000;
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        List<Query> qs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x1 = io.nextInt(), y1 = io.nextInt() + MX, x2 = io.nextInt(), y2 = io.nextInt() + MX;
            Query tmp;
            if (x1 == x2) {
                // vertical
                tmp = new Query();
                tmp.upd = 0; tmp.x = x1; tmp.y1 = y1; tmp.y2 = y2;
                qs.add(tmp);
            } else if (y1 == y2) {
                // horizontal
                tmp = new Query();
                tmp.upd = 1; tmp.x = x1; tmp.y1 = y1;
                qs.add(tmp);
                tmp = new Query();
                tmp.upd = -1; tmp.x = x2; tmp.y1 = y1;
                qs.add(tmp);
            }
        }
        Collections.sort(qs, Comparator.comparingInt(i -> i.x));
        long ans = 0;
        BIT bit = new BIT(2*MX+1);
        for (Query i : qs) {
            if (i.upd == 0) ans += bit.qry(i.y1, i.y2);
            else bit.add(i.y1, i.upd);
        }
        io.println(ans);
        io.close();
    }
}

class Query {
    byte upd; // 1 for + upd, 0 for a query, -1 for - upd
    int x, y1, y2;
}

class BIT {
    public int n;
    public long[] a, tree;
    public BIT(int n) {
        this.n = n;
        a = new long[n];
        tree = new long[n];
    }
    public void add(int i, long v) {
        a[i] += v;
        for (; i < n; i |= i + 1) tree[i] += v;
    }
    public long qry(int i) {
        long res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    public long qry(int i, int j) { return qry(j) - qry(i-1); }
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
