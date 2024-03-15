// created: 03-11-2024 Mon 10:26 AM

import java.util.*;
import java.io.*;

public class j_1941F {
    static FastIO io = new FastIO();
    static int lower_bound(int[] a, int x) {
        // first index such that a[i] >= x
        // returns a.length if no index found
        int l = 0, r = a.length;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    static void solve() {
        int n = io.nextInt(), m = io.nextInt(), k = io.nextInt();
        int[] a = new int[n], d = new int[m], f = new int[k];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        for (int i = 0; i < m; i++) d[i] = io.nextInt();
        for (int i = 0; i < k; i++) f[i] = io.nextInt();
        Arrays.sort(d); Arrays.sort(f);
        int mxi = 0;
        for (int i = 1; i < n-1; i++) if (a[mxi+1] - a[mxi] < a[i+1] - a[i]) mxi = i;
        int target = a[mxi] + (a[mxi+1] - a[mxi]) / 2;
        List<Integer> poss = new ArrayList<>();
        for (int i : d) {
            int target2 = target - i;
            int cand = lower_bound(f, target2);
            if (cand < k) poss.add(i + f[cand]);
            if (cand > 0) poss.add(i + f[cand-1]);
        }
        int ans = a[mxi+1] - a[mxi];
        for (int i : poss) {
            if (i < a[mxi] || i > a[mxi+1]) continue;
            ans = Math.min(ans, Math.max(i - a[mxi], a[mxi+1] - i));
        }
        for (int i = 0; i < mxi; i++) ans = Math.max(ans, a[i+1] - a[i]);
        for (int i = mxi+1; i < n-1; i++) ans = Math.max(ans, a[i+1] - a[i]);
        io.println(ans);
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
        io.close();
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
