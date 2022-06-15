// created: 06-15-2022 Wed 10:52 AM

import java.util.*;
import java.io.*;

public class DynamicRangeMin {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt(), q = io.nextInt();
        Segtree s = new Segtree(n);
        for (int i = 0; i < n; i++) s.upd(i, io.nextInt());
        for (int i = 0; i < q; i++) {
            int t = io.nextInt();
            if (t == 1) s.upd(io.nextInt()-1, io.nextInt());
            else io.println(s.qry(io.nextInt()-1, io.nextInt()-1));
        }
        io.close();
    }
    static class Segtree {
        private long[] tree;
        public int n;
        // the operator used in the segtree (must be associative and commutative)
        public long cmb(long a, long b) { return Math.min(a, b); }
        // the identity of the operator: cmb(id, x) = cmb(x, id) = x
        private final long id = Long.MAX_VALUE;
        // construct segment tree with n pieces of data
        public Segtree(int n) {
            this.n = n;
            tree = new long[2*n];
            Arrays.fill(tree, id);
        }
        // update value at position i to v
        public void upd(int i, long v) {
            i += n; tree[i] = v;
            while (i > 1) {
                i /= 2; tree[i] = cmb(tree[2*i], tree[2*i+1]);
            }
        }
        // query the range [a, b]
        public long qry(int a, int b) {
            long res = id;
            a += n; b += n;
            while (a <= b) {
                if (a % 2 == 1) res = cmb(res, tree[a++]);
                if (b % 2 == 0) res = cmb(res, tree[b--]);
                a /= 2; b /= 2;
            }
            return res;
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
