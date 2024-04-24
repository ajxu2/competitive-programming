// created: 04-16-2024 Tue 03:20 PM

import java.util.*;
import java.io.*;

public class DownloadSpeed {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        List<Pair>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        long[][] residual = new long[n][n];
        for (int i = 0; i < m; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1, c = io.nextInt();
            adj[u].add(new Pair(v, c)); adj[v].add(new Pair(u, c)); residual[u][v] += c;
        }
        long ans = 0;
        for (int scale = Integer.MAX_VALUE; scale > 0; scale >>= 1) {
            while (true) {
                // find augmenting path
                int[] par = new int[n]; Arrays.fill(par, -1);
                Queue<Integer> bfs = new ArrayDeque<>();
                par[0] = 0; bfs.offer(0);
                while (!bfs.isEmpty()) {
                    int cur = bfs.poll();
                    for (Pair i : adj[cur]) {
                        if (i.s >= scale && residual[cur][i.f] > 0 && par[i.f] == -1) {
                            par[i.f] = cur; bfs.offer(i.f);
                        }
                    }
                }
                if (par[n-1] == -1) break;
                // update residual network
                int cur = n-1; long delta = Long.MAX_VALUE;
                while (par[cur] != cur) {
                    delta = Math.min(delta, residual[par[cur]][cur]);
                    cur = par[cur];
                }
                cur = n-1;
                while (par[cur] != cur) {
                    residual[par[cur]][cur] -= delta;
                    residual[cur][par[cur]] += delta;
                    cur = par[cur];
                }
                ans += delta;
            }
        }
        io.println(ans);
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
