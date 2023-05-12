// created: 05-11-2023 Thu 01:03 PM

import java.util.*;
import java.io.*;

public class PointInPolygon {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        Point[] a = new Point[n+1];
        for (int i = 0; i < n; i++) a[i] = new Point(io.nextLong(), io.nextLong());
        a[n] = a[0];
        for (int i = 0; i < m; i++) {
            Point p = new Point(io.nextLong(), io.nextLong());
            int cnt = 0;
            // iterate over segments
            for (int j = 0; j < n; j++) {
                Point p1 = a[j], p2 = a[j+1];
                // make p1 lower than p2
                if (p1.y > p2.y) {
                    Point tmp = p1; p1 = p2; p2 = tmp;
                }
                // draw line going straight to the right, calculate intersection pts
                if (p1.y == p2.y) {
                    long mnx = Math.min(p1.x, p2.x), mxx = Math.max(p1.x, p2.x);
                    if (p.y == p1.y && mnx <= p.x && p.x <= mxx) {
                        cnt = -1;
                        break;
                    }
                    continue;
                }
                if (p1.y <= p.y && p.y <= p2.y && p.cross(p1, p2) == 0) {
                    cnt = -1;
                    break;
                }
                if (p.y <= p1.y || p2.y < p.y) continue;
                if (p.cross(p1, p2) > 0) cnt++;
            }
            if (cnt == -1) io.println("BOUNDARY");
            else if (cnt % 2 == 0) io.println("OUTSIDE");
            else io.println("INSIDE");
        }
        io.close();
    }
    static class Point {
        public long x, y;
        public Point(long x, long y) {
            this.x = x; this.y = y;
        }
        public long cross(Point p) {
            return x * p.y - y * p.x;
        }
        public long cross(Point p, Point q) {
            Point one = new Point(p.x - x, p.y - y);
            Point two = new Point(q.x - x, q.y - y);
            return one.cross(two);
        }
    }
    // credits to usaco.guide team for this template
    static class FastIO extends PrintWriter {
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
}
