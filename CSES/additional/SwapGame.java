// created: 04-14-2024 Sun 12:25 PM

import java.util.*;
import java.io.*;

public class SwapGame {
    static FastIO io = new FastIO();
    static int[] pow9 = new int[9];
    static int swp(int s, int a, int b) {
        // assume a < b
        int first = s / pow9[a] % 9, second = s / pow9[b] % 9;
        s += (second - first) * pow9[a];
        s += (first - second) * pow9[b];
        return s;
    }
    public static void main(String[] args) throws IOException {
        pow9[0] = 1;
        for (int i = 1; i < 9; i++) pow9[i] = pow9[i-1] * 9;
        int start = 0;
        for (int i = 0; i < 9; i++) start += (io.nextInt() - 1) * pow9[i];
        Queue<Pair> bfs = new ArrayDeque<>();
        BitSet vis = new BitSet();
        vis.set(start); bfs.offer(new Pair(start, 0));
        while (!bfs.isEmpty()) {
            Pair cur = bfs.poll();
            if (cur.f == 381367044) {
                io.println(cur.s);
                io.close();
                return;
            }
            for (int i = 0; i < 9; i++) {
                if (i % 3 == 2) continue;
                int nxt = swp(cur.f, i, i + 1);
                if (!vis.get(nxt)) {
                    vis.set(nxt); bfs.offer(new Pair(nxt, cur.s + 1));
                }
            }
            for (int i = 0; i < 6; i++) {
                int nxt = swp(cur.f, i, i + 3);
                if (!vis.get(nxt)) {
                    vis.set(nxt); bfs.offer(new Pair(nxt, cur.s + 1));
                }
            }
        }
        io.close();
    }
}

class Pair {
    int f, s;
    public Pair(int f, int s) {
        this.f = f; this.s = s;
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
