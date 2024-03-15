// created: 03-11-2024 Mon 11:23 AM

import java.util.*;
import java.io.*;

public class j_1941G {
    static FastIO io = new FastIO();
    static void solve() {
        int n = io.nextInt(), m = io.nextInt();
        Edge[] e = new Edge[m];
        int[] colors = new int[m];
        for (int i = 0; i < m; i++) {
            e[i] = new Edge(io.nextInt() - 1, io.nextInt() - 1, io.nextInt() - 1);
            colors[i] = e[i].c;
        }
        Arrays.sort(colors);
        for (int i = 0; i < m; i++) e[i].c = Arrays.binarySearch(colors, e[i].c);
        Set<Integer>[] groups = new Set[m];
        for (int i = 0; i < m; i++) groups[i] = new HashSet<>();
        for (Edge i : e) {
            groups[i.c].add(i.u); groups[i.c].add(i.v);
        }
        List<Integer>[] adj = new List[n+m];
        for (int i = 0; i < n+m; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j : groups[i]) {
                adj[n+i].add(j);
                adj[j].add(n+i);
            }
        }
        int start = io.nextInt() - 1, end = io.nextInt() - 1;
        int[] dist = new int[n+m]; Arrays.fill(dist, -1);
        Queue<Integer> bfs = new ArrayDeque<>();
        dist[start] = 0; bfs.offer(start);
        while (!bfs.isEmpty()) {
            int cur = bfs.poll();
            for (int i : adj[cur]) {
                if (dist[i] != -1) continue;
                dist[i] = dist[cur] + 1; bfs.offer(i);
            }
        }
        io.println(dist[end] / 2);
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
        io.close();
    }
}

class Edge {
    int u, v, c;
    public Edge(int u, int v, int c) {
        this.u = u; this.v = v; this.c = c;
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
