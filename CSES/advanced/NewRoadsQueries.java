// created: 04-15-2024 Mon 01:46 PM

import java.util.*;
import java.io.*;

public class NewRoadsQueries {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt(), q = io.nextInt();
        Edge[] edges = new Edge[2*m];
        int[] head = new int[n], nxt = new int[2*m];
        Arrays.fill(head, -1);
        for (int i = 0; i < m; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            edges[2*i] = new Edge(u, v, i + 1);
            nxt[2*i] = head[u]; head[u] = 2*i;
            edges[2*i+1] = new Edge(v, u, i + 1);
            nxt[2*i+1] = head[v]; head[v] = 2*i+1;
        }
        // jarnik's algorithm
        boolean[] vis = new boolean[n];
        int[] par = new int[n], parval = new int[n], depth = new int[n], cc = new int[n];
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            Queue<Edge> pq = new PriorityQueue<Edge>(Comparator.comparingInt(e -> e.w));
            pq.offer(new Edge(i, i, 0));
            while (!pq.isEmpty()) {
                Edge cur = pq.poll();
                if (vis[cur.v]) continue;
                vis[cur.v] = true; par[cur.v] = cur.u; parval[cur.v] = cur.w;
                depth[cur.v] = depth[cur.u] + 1;
                cc[cur.v] = cur.u == cur.v ? cur.u : cc[cur.u];
                for (int whar = head[cur.v]; whar != -1; whar = nxt[whar]) {
                    Edge j = edges[whar];
                    if (!vis[j.v]) pq.offer(j);
                }
            }
        }
        int[][] jmp = new int[18][n], jmpval = new int[18][n];
        jmp[0] = par; jmpval[0] = parval;
        for (int i = 1; i < 18; i++) {
            for (int j = 0; j < n; j++) {
                jmp[i][j] = jmp[i-1][jmp[i-1][j]];
                jmpval[i][j] = Math.max(jmpval[i-1][j], jmpval[i-1][jmp[i-1][j]]);
            }
        }
        StringBuilder out = new StringBuilder();
        while (q --> 0) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            if (cc[u] != cc[v]) {
                out.append("-1\n");
                continue;
            }
            if (depth[u] > depth[v]) { u ^= v; v ^= u; u ^= v; }
            int dd = depth[v] - depth[u], ans = 0;
            for (int i = 17; i >= 0; i--) if ((dd & (1 << i)) != 0) {
                ans = Math.max(ans, jmpval[i][v]);
                v = jmp[i][v];
            }
            if (u == v) {
                out.append(ans).append('\n');
                continue;
            }
            for (int i = 17; i >= 0; i--) if (jmp[i][u] != jmp[i][v]) {
                ans = Math.max(ans, Math.max(jmpval[i][u], jmpval[i][v]));
                u = jmp[i][u]; v = jmp[i][v];
            }
            ans = Math.max(ans, Math.max(jmpval[0][u], jmpval[0][v]));
            out.append(ans).append('\n');
        }
        io.print(out);
        io.close();
    }
}

class Edge {
    int u, v, w;
    public Edge(int u, int v, int w) {
        this.u = u; this.v = v; this.w = w;
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
