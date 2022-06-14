// created: 06-14-2022 Tue 12:33 PM

import java.util.*;
import java.io.*;

public class ModernArt2 {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO("art2.in", "art2.out");
        int n = io.nextInt();
        int[] a = new int[n];
        int[] lst = new int[n+1]; Arrays.fill(lst, -1);
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
            lst[a[i]] = i;
        }
        boolean[] on = new boolean[n+1];
        Stack<Integer> s = new Stack<>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (!s.isEmpty()) {
                    ans = -1; break;
                } else continue;
            }
            if (s.isEmpty() || a[i] != s.peek()) {
                if (on[a[i]]) {
                    ans = -1; break;
                }
                s.push(a[i]); on[a[i]] = true;
            }
            ans = Math.max(ans, s.size());
            if (lst[a[i]] == i) s.pop();
        }
        io.println(ans);
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
