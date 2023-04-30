// created: 04-29-2023 Sat 03:02 PM

import java.util.*;
import java.io.*;

public class j_1773A {
    static FastIO io = new FastIO();
    public static void solve() throws IOException {
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt() - 1;
        Random r = new Random();
        for (int i = 0; i < 500; i++) {
            // probably enough iterations
            // create p array
            int[] p = new int[n];
            for (int j = 0; j < n; j++) p[j] = j;
            for (int j = n-1; j > 0; j--) {
                int swap = r.nextInt(j+1);
                int tmp = p[j]; p[j] = p[swap]; p[swap] = tmp;
            }
            // calculate q array
            int[] q = new int[n];
            for (int j = 0; j < n; j++) q[a[p[j]]] = j;
            // is it ok?
            boolean ok = true;
            for (int j = 0; j < n; j++) if (p[j] == j) ok = false;
            for (int j = 0; j < n; j++) if (q[j] == j) ok = false;
            if (ok) {
                io.println("Possible");
                for (int j : p) io.print(j+1 + " "); io.println();
                for (int j : q) io.print(j+1 + " "); io.println();
                return;
            }
        }
        io.println("Impossible");
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
        io.close();
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
