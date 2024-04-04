// created: 04-02-2024 Tue 10:34 PM

import java.util.*;
import java.io.*;

public class MinimumEuclideanDistance {
    static FastIO io = new FastIO();
    static final long INF = (long)9e18;
    static long sq(long x) { return x * x; }
    static long dist(Point q, Point w) {
        return sq(w.x - q.x) + sq(w.y - q.y);
    }
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        Point[] a = new Point[n];
        for (int i = 0; i < n; i++) a[i] = new Point(io.nextInt(), io.nextInt());
        Arrays.sort(a, new Comparator<Point>() {
            public int compare(Point q, Point w) {
                if (q.x == w.x) return Long.compare(q.y, w.y);
                return Long.compare(q.x, w.x);
            }
        });
        TreeSet<Point> se = new TreeSet<>(new Comparator<Point>() {
            public int compare(Point q, Point w) {
                if (q.y == w.y) return Long.compare(q.x, w.x);
                return Long.compare(q.y, w.y);
            }
        });
        long ans = INF;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            while (ptr < i && sq(a[i].x - a[ptr].x) > ans) {
                se.remove(a[ptr]);
                ptr++;
            }
            long realdist = (long)Math.ceil(Math.sqrt(ans));
            Point test = se.higher(new Point(-INF, a[i].y - realdist));
            while (test != null && test.y <= a[i].y + realdist) {
                ans = Math.min(ans, dist(test, a[i]));
                test = se.higher(test);
            }
            se.add(a[i]);
        }
        io.println(ans);
        io.close();
    }
}

class Point {
    public long x, y;
    public Point(long x, long y) {
        this.x = x; this.y = y;
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
