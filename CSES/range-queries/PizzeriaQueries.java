// created: 01-27-2024 Sat 11:30 PM

import java.util.*;
import java.io.*;

public class PizzeriaQueries {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        Segtree s = new Segtree(n);
        for (int i = 0; i < n; i++) {
            int x = io.nextInt();
            s.upd(i, new State(1, x, x));
        }
        for (int i = 0; i < q; i++) {
            int t = io.nextInt();
            if (t == 1) {
                int k = io.nextInt() - 1, x = io.nextInt();
                s.upd(k, new State(1, x, x));
            } else {
                int k = io.nextInt() - 1;
                io.println(Math.min(s.qry(0, k).ansr, s.qry(k, n-1).ansl));
            }
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
    public void upd(int i, State x) {
        i += n;
        tree[i] = x; i >>= 1;
        for (; i > 0; i >>= 1) tree[i] = tree[i << 1].cmb(tree[i << 1 ^ 1]);
    }
    public State qry(int l, int r) {
        l += n; r += n;
        State rl = State.id, rr = State.id;
        while (l <= r) {
            if ((l & 1) == 1) rl = rl.cmb(tree[l++]);
            if ((r & 1) == 0) rr = tree[r--].cmb(rr);
            l >>= 1; r >>= 1;
        }
        return rl.cmb(rr);
    }
}

class State {
    int len; long ansl, ansr;
    public State(int len, long ansl, long ansr) {
        this.len = len;
        this.ansl = ansl;
        this.ansr = ansr;
    }
    static final State id = new State(0, (long)1e18, (long)1e18);
    public State cmb(State o) { return new State(len + o.len, Math.min(ansl, len + o.ansl), Math.min(o.len + ansr, o.ansr)); }
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
