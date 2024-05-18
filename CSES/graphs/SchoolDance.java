// created: 04-23-2024 Tue 11:58 PM

import java.util.*;
import java.io.*;

public class SchoolDance {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt(), k = io.nextInt();
        int nodes = n + m + 2; // 0 and 1 "dummy nodes", 2 through n+1 boys, n+2 through n+m+1 girls
        List<Integer>[] adj = new List[nodes];
        for (int i = 0; i < nodes; i++) adj[i] = new ArrayList<>();
        boolean[][] open = new boolean[nodes][nodes];
        for (int i = 2; i <= n+1; i++) {
            adj[0].add(i); adj[i].add(0); open[0][i] = true;
        }
        for (int i = n+2; i <= n+m+1; i++) {
            adj[i].add(1); adj[1].add(i); open[i][1] = true;
        }
        for (int i = 0; i < k; i++) {
            int u = io.nextInt() + 1, v = io.nextInt() + n + 1;
            adj[u].add(v); adj[v].add(u); open[u][v] = true;
        }
        int[] par = new int[nodes]; 
        while (true) {
            // find augmenting path
            Arrays.fill(par, -1);
            Queue<Integer> bfs = new ArrayDeque<>();
            par[0] = 0; bfs.offer(0);
            while (!bfs.isEmpty()) {
                int cur = bfs.poll();
                for (int i : adj[cur]) {
                    if (open[cur][i] && par[i] == -1) {
                        par[i] = cur; bfs.offer(i);
                    }
                }
            }
            if (par[1] == -1) break;
            // update residual network
            int cur = 1;
            while (par[cur] != cur) {
                open[par[cur]][cur] = false;
                open[cur][par[cur]] = true;
                cur = par[cur];
            }
        }
        Set<Pair> ans = new TreeSet<>();
        for (int i = 2; i <= n+1; i++) {
            for (int j : adj[i]) {
                if (j == 0) continue;
                if (!open[i][j]) ans.add(new Pair(i - 1, j - n - 1));
            }
        }
        StringBuilder out = new StringBuilder();
        out.append(ans.size()).append('\n');
        for (Pair i : ans) out.append(i.f).append(' ').append(i.s).append('\n');
        io.print(out);
        io.close();
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
