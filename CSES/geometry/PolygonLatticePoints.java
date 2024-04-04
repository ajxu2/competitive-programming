// created: 04-02-2024 Tue 10:06 PM

import java.util.*;
import java.io.*;

public class PolygonLatticePoints {
    static FastIO io = new FastIO();
    static long gcd(long x, long y) { return y == 0 ? x : gcd(y, x % y); }
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        Point[] a = new Point[n+1];
        for (int i = 0; i < n; i++) a[i] = new Point(io.nextInt(), io.nextInt());
        a[n] = a[0];
        long area = 0; // twice area
        for (int i = 0; i < n; i++) {
            area += a[i].x * a[i+1].y;
            area -= a[i].y * a[i+1].x;
        }
        if (area < 0) area = -area;
        long boundary = 0;
        for (int i = 0; i < n; i++) boundary += gcd(Math.abs(a[i+1].x - a[i].x), Math.abs(a[i+1].y - a[i].y));
        // 2A = 2i + b - 2
        long interior = area - boundary + 2 >> 1;
        io.println(interior + " " + boundary);
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
