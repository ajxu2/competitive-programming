// created: 02-24-2024 Sat 05:23 PM

import java.util.*;
import java.io.*;

public class IncreasingArrayQueries {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        LazySeg s = new LazySeg(n);
        PrefixSum p = new PrefixSum(a);
        List<Pair>[] queries = new List[n];
        for (int i = 0; i < n; i++) queries[i] = new ArrayList<>();
        long[] ans = new long[q];
        for (int i = 0; i < q; i++) {
            int l = io.nextInt() - 1, r = io.nextInt() - 1;
            queries[l].add(new Pair(r, i));
        }
        for (int i = n - 1; i >= 0; i--) {
            int r = s.lower_bound(a[i]) - 1;
            if (i <= r) s.updSet(i, r, a[i]);
            for (Pair j : queries[i]) ans[j.s] = s.qrySum(i, j.f) - p.qry(i, j.f);
        }
        for (long i : ans) io.println(i);
        io.close();
    }
}

class Pair {
    int f, s;
    public Pair(int f, int s) {
        this.f = f; this.s = s;
    }
}

class PrefixSum {
    long[] p;
    public PrefixSum(long[] a) {
        p = Arrays.copyOf(a, a.length);
        for (int i = 1; i < a.length; i++) p[i] += p[i-1];
    }
    public long qry(int l, int r) {
        return l == 0 ? p[r] : p[r] - p[l-1];
    }
}

class LazySeg {
    int l, r;
    long vAdd = 0, vMax = 0, lzSet = 0;
    LazySeg left, right;
    public LazySeg(int l, int r) {
        this.l = l; this.r = r;
        if (l == r) return;
        int mid = (l + r) / 2;
        left = new LazySeg(l, mid); right = new LazySeg(mid + 1, r);
    }
    public LazySeg(int n) { this(0, n - 1); }
    public void push() {
        if (l == r) {
            if (lzSet != 0) {
                vAdd = lzSet; vMax = lzSet;
            }
            lzSet = 0;
            return;
        }
        if (lzSet != 0) {
            vAdd = (r - l + 1) * lzSet; vMax = lzSet;
            left.lzSet = lzSet; right.lzSet = lzSet;
            lzSet = 0;
        }
    }
    public void pull() {
        vAdd = left.vAdd + right.vAdd;
        vMax = Math.max(left.vMax, right.vMax);
    }
    public long qrySum(int ll, int rr) {
        push();
        if (ll <= l && r <= rr) return vAdd;
        if (r < ll || rr < l) return 0;
        return left.qrySum(ll, rr) + right.qrySum(ll, rr);
    }
    public void updSet(int ll, int rr, long x) {
        if (ll <= l && r <= rr) {
            lzSet = x;
            push();
            return;
        }
        push();
        if (r < ll || rr < l) return;
        left.updSet(ll, rr, x); right.updSet(ll, rr, x);
        pull();
    }
    public int lower_bound(long x) {
        // find first index >= x, assuming array is monotonic
        if (l == r) return l;
        left.push(); right.push();
        if (right.vMax < x) return r + 1;
        else if (left.vMax < x) return right.lower_bound(x);
        else return left.lower_bound(x);
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
