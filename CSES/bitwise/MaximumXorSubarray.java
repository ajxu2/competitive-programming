// created: 04-18-2024 Thu 07:07 PM

import java.util.*;
import java.io.*;

public class MaximumXorSubarray {
    static FastIO io = new FastIO();
    static int[][] trie = new int[2][6200000];
    static int nodes = 1;
    static void add(int x) {
        int cur = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (trie[bit][cur] == -1) trie[bit][cur] = nodes++;
            cur = trie[bit][cur];
        }
    }
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        for (int i = 0; i < 2; i++) Arrays.fill(trie[i], -1);
        add(0);
        int ans = 0, p = 0;
        for (int i : a) {
            p ^= i;
            int cur = 0, res = 0;
            for (int j = 30; j >= 0; j--) {
                int bit = (p >> j) & 1;
                if (trie[bit ^ 1][cur] != -1) bit ^= 1;
                cur = trie[bit][cur];
                res <<= 1; res |= bit;
            }
            ans = Math.max(ans, p ^ res);
            add(p);
        }
        io.println(ans);
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
