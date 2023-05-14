// created: 05-14-2023 Sun 10:14 AM

import java.util.*;
import java.io.*;

public class j_1828D {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) {
            int n = io.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = io.nextInt();
            long ans = 0;
            for (int i = 0; i < n; i++) {
                int mx = a[i];
                ArrayList<Integer> s = new ArrayList<>();
                for (int j = i+1; j < n; j++) {
                    if (a[j] > mx) {
                        s.add(mx); mx = a[j];
                    } else {
                        while (!s.isEmpty() && s.get(s.size()-1) > a[j]) s.remove(s.size()-1);
                    }
                    ans += (j - i - s.size());
                }
            }
            io.println(ans);
        }
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
