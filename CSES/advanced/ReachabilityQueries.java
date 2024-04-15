// created: 04-13-2024 Sat 11:05 AM

import java.util.*;
import java.io.*;

public class ReachabilityQueries {
    static FastIO io = new FastIO();
    static int[] head, to, nxt, rhead, rto, rnxt;
    static int[] scc, order;
    static boolean[] vis;
    static int idx;
    static void dfs1(int x) {
        if (vis[x]) return;
        vis[x] = true;
        for (int whar = head[x]; whar != -1; whar = nxt[whar]) {
            int i = to[whar];
            dfs1(i);
        }
        order[idx--] = x;
    }
    static void dfs2(int x) {
        if (scc[x] != -1) return;
        scc[x] = idx;
        for (int whar = rhead[x]; whar != -1; whar = rnxt[whar]) {
            int i = rto[whar];
            dfs2(i);
        }
    }
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt(), q = io.nextInt();
        head = new int[n]; to = new int[m]; nxt = new int[m];
        int[] from = new int[m];
        rhead = new int[n]; rto = new int[m]; rnxt = new int[m];
        Arrays.fill(head, -1); Arrays.fill(rhead, -1);
        for (int i = 0; i < m; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            to[i] = v; nxt[i] = head[u]; head[u] = i;
            rto[i] = u; rnxt[i] = rhead[v]; rhead[v] = i;
            from[i] = u;
        }
        vis = new boolean[n];
        order = new int[n];
        idx = n - 1;
        for (int i = 0; i < n; i++) dfs1(i);
        scc = new int[n];
        Arrays.fill(scc, -1);
        idx = 0;
        for (int i : order) {
            if (scc[i] != -1) continue;
            dfs2(i); idx++;
        }
        // create condensation graph
        int[] chead = new int[idx], cto = new int[m], cnxt = new int[m];
        Arrays.fill(chead, -1);
        for (int whar = 0; whar < m; whar++) {
            int i = scc[from[whar]], j = scc[to[whar]];
            cto[whar] = j; cnxt[whar] = chead[i]; chead[i] = whar;
        }
        BitSet[] dp = new BitSet[idx];
        for (int i = idx - 1; i >= 0; i--) {
            dp[i] = new BitSet();
            dp[i].set(i);
            for (int whar = chead[i]; whar != -1; whar = cnxt[whar]) {
                int j = cto[whar];
                dp[i].or(dp[j]);
            }
        }
        StringBuilder out = new StringBuilder();
        while (q --> 0) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            out.append(dp[scc[u]].get(scc[v]) ? "YES" : "NO").append('\n');
        }
        io.print(out);
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
