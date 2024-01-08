// created: 01-06-2024 Sat 09:08 PM

import java.util.*;
import java.io.*;

public class NestedRangesCount {
    static FastIO io = new FastIO();
    static Random r = new Random();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        Seg[] s = new Seg[n];
        int[] y = new int[n]; // for coordinate compression
        for (int i = 0; i < n; i++) {
            s[i] = new Seg();
            s[i].f = io.nextInt(); s[i].s = io.nextInt(); s[i].i = i;
            y[i] = s[i].s;
        }
        // shuffle, then sort y
        for (int i = n-1; i >= 1; i--) {
            int swp = r.nextInt(i+1);
            int tmp = y[swp]; y[swp] = y[i]; y[i] = tmp;
        }
        Arrays.sort(y);
        // extract answers
        Arrays.sort(s, new Comparator<Seg>() {
            public int compare(Seg s1, Seg s2) {
                if (s1.f == s2.f) return s2.s - s1.s;
                return s1.f - s2.f;
            }
        });
        int[] ans1 = new int[n], ans2 = new int[n];
        BIT b = new BIT(n);
        for (int i = 0; i < n; i++) {
            int tmp = Arrays.binarySearch(y, s[i].s);
            ans2[s[i].i] = b.qry(tmp, n-1);
            b.add(tmp, 1);
        }
        b = new BIT(n);
        for (int i = n-1; i >= 0; i--) {
            int tmp = Arrays.binarySearch(y, s[i].s);
            ans1[s[i].i] = b.qry(0, tmp);
            b.add(tmp, 1);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(ans1[i]);
            sb.append(i == n-1 ? "\n" : " ");
        }
        for (int i = 0; i < n; i++) {
            sb.append(ans2[i]);
            sb.append(i == n-1 ? "\n" : " ");
        }
        io.print(sb);
        io.close();
    }
    static class Seg {
        public int f, s, i;
    }
    static class BIT {
        public int n;
        public int[] a, tree;
        public BIT(int n) {
            this.n = n;
            a = new int[n];
            tree = new int[n];
        }
        public void add(int i, int v) {
            a[i] += v;
            for (; i < n; i |= i + 1) tree[i] += v;
        }
        public void upd(int i, int v) { add(i, v - a[i]); }
        public int qry(int i) {
            int res = 0;
            for (; i >= 0; i = (i & i+1) - 1) res += tree[i];
            return res;
        }
        public int qry(int i, int j) { return qry(j) - qry(i-1); }
        public int lower_bound(int v) {
            // returns first x st qry(x) >= v
            // or n if no such elements exist
            int res = 0; int sofar = 0;
            for (int i = 30; i >= 0; i--) {
                if (res + (1 << i) > n) continue;
                if (sofar + tree[res+(1<<i)-1] < v) {
                    res += 1 << i;
                    sofar += tree[res-1];
                }
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
