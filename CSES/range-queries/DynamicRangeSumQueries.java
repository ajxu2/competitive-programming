// created: 06-15-2022 Wed 10:52 AM

import java.util.*;
import java.io.*;

public class DynamicRangeSumQueries {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt(), q = io.nextInt();
        BIT b = new BIT(n);
        for (int i = 0; i < n; i++) b.upd(i+1, io.nextInt());
        for (int i = 0; i < q; i++) {
            int t = io.nextInt();
            if (t == 1) b.upd(io.nextInt(), io.nextInt());
            else io.println(b.qry(io.nextInt(), io.nextInt()));
        }
        io.close();
    }
    static class BIT {
        private long[] tree;
        public int n;
        // construct BIT with n pieces of data
        public BIT(int n) {
            this.n = n;
            tree = new long[n+1];
        }
        // update value at position i to v (1-indexed)
        public void upd(int i, long v) {
            long d = v - qry(i, i);
            while (i <= n) {
                tree[i] += d;
                i += i & -i;
            }
        }
        // query the sum from [1, a] (1-indexed)
        public long qry(int a) {
            long res = 0;
            while (a > 0) {
                res += tree[a];
                a -= a & -a;
            }
            return res;
        }
        // query the sum from [a, b] (a and b are 1-indexed)
        public long qry(int a, int b) {
            return qry(b) - qry(a-1);
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
