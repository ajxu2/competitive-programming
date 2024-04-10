// created: 04-09-2024 Tue 10:36 PM

import java.util.*;
import java.io.*;

public class PalindromeQueries {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        String s = io.next();
        Segtree seg = new Segtree(s), segr = new Segtree(new StringBuilder(s).reverse().toString());
        StringBuilder out = new StringBuilder();
        while (q --> 0) {
            int type = io.nextInt();
            if (type == 1) {
                int k = io.nextInt() - 1; char x = io.next().charAt(0);
                seg.upd(k, x); segr.upd(n - 1 - k, x);
            } else {
                int l = io.nextInt() - 1, r = io.nextInt() - 1;
                int mid = (l + r) >> 1;
                long hsh1, hsh2;
                if ((r - l & 1) == 0) {
                    // odd length
                    hsh1 = seg.qry(l, mid).hsh; hsh2 = segr.qry(n - 1 - r, n - 1 - mid).hsh;
                } else {
                    // even length
                    hsh1 = seg.qry(l, mid).hsh; hsh2 = segr.qry(n - 1 - r, n - 1 - (mid + 1)).hsh;
                }
                out.append(hsh1 == hsh2 ? "YES" : "NO").append('\n');
            }
        }
        io.print(out);
        io.close();
    }
}

class Segtree {
    public int n;
    public StringHash[] tree;
    public Segtree(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        tree = new StringHash[this.n << 1];
        Arrays.fill(tree, StringHash.id);
    }
    public Segtree(String s) {
        this(s.length());
        for (int i = 0; i < s.length(); i++) tree[n + i] = new StringHash(1, s.charAt(i));
        for (int i = n - 1; i >= 1; i--) tree[i] = tree[i << 1].cmb(tree[i << 1 ^ 1]);
    }
    public void upd(int i, char x) {
        i += n;
        tree[i].hsh = x; i >>= 1;
        for (; i > 0; i >>= 1) tree[i] = tree[i << 1].cmb(tree[i << 1 ^ 1]);
    }
    public StringHash qry(int l, int r) {
        l += n; r += n;
        StringHash rl = StringHash.id, rr = StringHash.id;
        while (l <= r) {
            if ((l & 1) == 1) rl = rl.cmb(tree[l++]);
            if ((r & 1) == 0) rr = tree[r--].cmb(rr);
            l >>= 1; r >>= 1;
        }
        return rl.cmb(rr);
    }
}

class StringHash {
    int len; long hsh;
    static long[] pow = new long[]{1};
    static final int MOD = 2_000_000_011, p = new Random().nextInt(MOD);
    static final StringHash id = new StringHash(0, 0);
    public StringHash(int len, long hsh) {
        this.len = len; this.hsh = hsh;
        while (pow.length < len + 1) {
            pow = Arrays.copyOf(pow, pow.length << 1);
            for (int i = pow.length >> 1; i < pow.length; i++) pow[i] = pow[i-1] * p % MOD;
        }
    }
    public StringHash cmb(StringHash o) { return new StringHash(len + o.len, (hsh * pow[o.len] + o.hsh) % MOD); }
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
