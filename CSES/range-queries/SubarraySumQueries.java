// created: 02-18-2024 Sun 04:43 PM

import java.util.*;
import java.io.*;

public class SubarraySumQueries {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        State[] a = new State[n];
        for (int i = 0; i < n; i++) {
            int x = io.nextInt(), xp = Math.max(x, 0);
            a[i] = new State(x, xp, xp, xp);
        }
        Segtree s = new Segtree(a);
        while (m --> 0) {
            int k = io.nextInt() - 1, x = io.nextInt(), xp = Math.max(x, 0);
            s.upd(k, new State(x, xp, xp, xp));
            io.println(s.tree[1].ans);
        }
        io.close();
    }
}

class Segtree {
    public int n;
    public State[] tree;
    public Segtree(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        tree = new State[this.n << 1];
        Arrays.fill(tree, State.id);
    }
    public Segtree(State[] a) {
        this(a.length);
        for (int i = 0; i < a.length; i++) tree[i + n] = a[i];
        for (int i = n - 1; i >= 1; i--) tree[i] = tree[i << 1].cmb(tree[i << 1 ^ 1]);
    }
    public void upd(int i, State x) {
        i += n;
        tree[i] = x; i >>= 1;
        for (; i > 0; i >>= 1) tree[i] = tree[i << 1].cmb(tree[i << 1 ^ 1]);
    }
}

class State {
    long sum, maxp, maxs, ans;
    public State(long sum, long maxp, long maxs, long ans) {
        this.sum = sum; this.maxp = maxp; this.maxs = maxs; this.ans = ans;
    }
    static final State id = new State(0, 0, 0, 0);
    public State cmb(State o) {
        return new State(sum + o.sum, Math.max(maxp, sum + o.maxp), Math.max(o.maxs, o.sum + maxs), Math.max(Math.max(ans, o.ans), maxs + o.maxp));
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

