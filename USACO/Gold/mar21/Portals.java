// created: 06-13-2022 Mon 01:38 PM

import java.util.*;
import java.io.*;

public class Portals {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt();
        Edge[] el = new Edge[3*n];
        for (int i = 0; i < n; i++) {
            int c = io.nextInt(), p1 = io.nextInt(), p2 = io.nextInt(), p3 = io.nextInt(), p4 = io.nextInt();
            el[3*i] = new Edge(p1, p2, 0);
            el[3*i+1] = new Edge(p3, p4, 0);
            el[3*i+2] = new Edge(p1, p3, c);
        }
        Arrays.sort(el);
        DSU d = new DSU(2*n+1);
        int ans = 0;
        for (int i = 0; i < 3*n; i++) {
            if (d.unite(el[i].a, el[i].b)) ans += el[i].w;
        }
        io.println(ans);
        io.close();
    }
    static class Edge implements Comparable<Edge> {
        int a, b, w;
        public Edge(int a, int b, int w) {
            this.a = a; this.b = b; this.w = w;
        }
        public int compareTo(Edge y) {
            return Integer.compare(w, y.w);
        }
    }
    static class DSU {
        public int[] parent, sz;
        public DSU(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;
            sz = new int[n];
            for (int i = 0; i < n; i++) sz[i] = 1;
        }
        // find representative of a node with path compression
        public int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        // find if two nodes are in the same CC
        public boolean same(int x, int y) {
            return (find(x) == find(y));
        }
        // unite two sets by size
        // returns true if any CCs were united
        public boolean unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            // x big y small
            if (sz[x] < sz[y]) {
                int tmp = x; x = y; y = tmp;
            }
            parent[y] = x;
            sz[x] += sz[y];
            return true;
        }
        // get the size of a CC
        public int size(int x) {
            return sz[find(x)];
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
