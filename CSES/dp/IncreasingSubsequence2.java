// created: 04-18-2024 Thu 07:40 PM

import java.util.*;
import java.io.*;

public class IncreasingSubsequence2 {
    static FastIO io = new FastIO();
    static Random r = new Random();
    static int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        // compress
        int[] b = Arrays.copyOf(a, n);
        ruffleSort(b);
        for (int i = 0; i < n; i++) a[i] = Arrays.binarySearch(b, a[i]);
        BIT bit = new BIT(n);
        for (int i : a) bit.add(i, bit.qry(i - 1) + 1);
        io.println(bit.qry(n - 1));
        io.close();
    }
    static void ruffleSort(int[] a) {
        for (int i = a.length - 1; i > 0; i--) {
            int swp = r.nextInt(i + 1);
            int tmp = a[i]; a[i] = a[swp]; a[swp] = tmp;
        }
        Arrays.sort(a);
    }
    static class BIT {
        public int n;
        public long[] a, tree;
        public BIT(int n) {
            this.n = n;
            a = new long[n];
            tree = new long[n];
        }
        public void add(int i, long v) {
            a[i] += v; a[i] %= MOD;
            for (; i < n; i |= i + 1) {
                tree[i] += v; tree[i] %= MOD;
            }
        }
        public long qry(int i) {
            long res = 0;
            for (; i >= 0; i &= i + 1, i--) res += tree[i];
            return res % MOD;
        }
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
