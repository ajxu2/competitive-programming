// created: 05-06-2024 Mon 07:07 PM

import java.util.*;
import java.io.*;

public class NetworkBreakdown {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt(), k = io.nextInt();
        Pair[] edges = new Pair[m];
        for (int i = 0; i < m; i++) edges[i] = new Pair(io.nextInt() - 1, io.nextInt() - 1);
        Arrays.sort(edges);
        int[] queries = new int[k];
        boolean[] existing = new boolean[m];
        Arrays.fill(existing, true);
        for (int i = 0; i < k; i++) {
            Pair search = new Pair(io.nextInt() - 1, io.nextInt() - 1);
            if (Arrays.binarySearch(edges, search) < 0) {
                search.f ^= search.s; search.s ^= search.f; search.f ^= search.s;
            }
            queries[i] = Arrays.binarySearch(edges, search);
            existing[queries[i]] = false;
        }
        int[] ans = new int[k];
        int cur = n;
        DSU dsu = new DSU(n);
        for (int i = 0; i < m; i++) if (existing[i] && dsu.unite(edges[i].f, edges[i].s)) cur--;
        for (int i = k-1; i >= 0; i--) {
            ans[i] = cur;
            if (dsu.unite(edges[queries[i]].f, edges[queries[i]].s)) cur--;
        }
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < k; i++) out.append(ans[i]).append(i == k-1 ? '\n' : ' ');
        io.print(out);
        io.close();
    }
}

class DSU {
    int[] e;
    public DSU(int n) {
        e = new int[n];
        Arrays.fill(e, -1);
    }
    public int find(int x) { return e[x] < 0 ? x : (e[x] = find(e[x])); }
    public boolean unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (-e[x] > -e[y]) { x ^= y; y ^= x; x ^= y; }
        e[y] += e[x]; e[x] = y;
        return true;
    }
}

class Pair implements Comparable<Pair> {
    int f, s;
    public Pair(int f, int s) {
        this.f = f; this.s = s;
    }
    public int compareTo(Pair o) {
        if (f == o.f) return Integer.compare(s, o.s);
        return Integer.compare(f, o.f);
    }
    public String toString() { return "(" + f + ", " + s + ")"; }
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
