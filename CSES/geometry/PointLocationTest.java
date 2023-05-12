// created: 05-03-2023 Wed 03:31 PM
 
import java.util.*;
import java.io.*;
 
public class PointLocationTest {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) {
            Point[] a = new Point[4];
            for (int i = 0; i < 3; i++) a[i] = new Point(io.nextLong(), io.nextLong());
            a[3] = a[0];
            // get area of triangle, positive if ccw
            long area = 0;
            for (int i = 0; i < 3; i++) area += a[i].x * a[i+1].y;
            for (int i = 0; i < 3; i++) area -= a[i].y * a[i+1].x;
            if (area > 0) io.println("LEFT");
            else if (area < 0) io.println("RIGHT");
            else io.println("TOUCH");
        }
        io.close();
    }
    static class Point {
        public long x, y;
        public Point(long x, long y) {
            this.x = x; this.y = y;
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
