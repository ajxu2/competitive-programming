// created: 04-02-2024 Tue 09:41 PM

import java.util.*;
import java.io.*;

public class LineSegmentIntersection {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        StringBuilder out = new StringBuilder();
        while (T --> 0) {
            Vec[] a = new Vec[4];
            for (int i = 0; i < 4; i++) a[i] = new Vec(io.nextInt(), io.nextInt());
            boolean ans;
            if (a[0].cross(a[1], a[2]) == 0 && a[1].cross(a[2], a[3]) == 0) {
                // all 4 collinear
                ans = false;
                ans |= Long.signum(a[0].dot(a[2], a[3])) <= 0;
                ans |= Long.signum(a[1].dot(a[2], a[3])) <= 0;
                ans |= Long.signum(a[2].dot(a[0], a[1])) <= 0;
                ans |= Long.signum(a[3].dot(a[0], a[1])) <= 0;
            } else {
                ans = true;
                ans &= Long.signum(a[0].cross(a[2], a[3])) != Long.signum(a[1].cross(a[2], a[3]));
                ans &= Long.signum(a[2].cross(a[0], a[1])) != Long.signum(a[3].cross(a[0], a[1]));
            }
            out.append(ans ? "YES" : "NO").append('\n');
        }
        io.print(out);
        io.close();
    }
}

class Vec {
    public long x, y;
    public Vec(long x, long y) {
        this.x = x; this.y = y;
    }
    public Vec sub(Vec o) { return new Vec(x - o.x, y - o.y); }
    public long cross(Vec o) { return x * o.y - y * o.x; }
    public long cross(Vec o1, Vec o2) { return o1.sub(this).cross(o2.sub(this)); }
    public long dot(Vec o) { return x * o.x + y * o.y; }
    public long dot(Vec o1, Vec o2) { return o1.sub(this).dot(o2.sub(this)); }
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
