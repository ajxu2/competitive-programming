// created: 01-19-2024 Fri 10:39 AM

import java.util.*;
import java.io.*;

public class CoinCollector {
    static FastIO io = new FastIO();
    static int n, m;
    static List<Integer>[] adj, radj;
    static int[] coins;
    static long[] scccoins, dp;
    static boolean[] vis;
    static List<Integer> order;
    static int[] comp;
    static List<Integer>[] sccadj;
    static int cur = -1;
    static void dfs(int x) {
        for (int i : adj[x]) {
            if (vis[i]) continue;
            vis[i] = true; dfs(i);
        }
        order.add(x);
    }
    static void dfs2(int x) {
        for (int i : radj[x]) {
            if (vis[i]) continue;
            vis[i] = true; comp[i] = cur; dfs2(i);
        }
    }
    public static void main(String[] args) throws IOException {
        // kosaraju, AGAIN
        // toposort SCCs and easy
        n = io.nextInt(); m = io.nextInt();
        coins = new int[n];
        for (int i = 0; i < n; i++) coins[i] = io.nextInt();
        adj = new List[n]; radj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
            radj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int a = io.nextInt() - 1, b = io.nextInt() - 1;
            adj[a].add(b); radj[b].add(a);
        }
        vis = new boolean[n];
        order = new ArrayList<>();
        // 1st stage, get order of processing times
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true; dfs(i);
        }
        Collections.reverse(order);
        // 2nd stage, reverse edges and extract SCCs
        Arrays.fill(vis, false);
        comp = new int[n]; sccadj = new List[n];
        for (int i = 0; i < n; i++) sccadj[i] = new ArrayList<Integer>();
        for (int i : order) {
            if (vis[i]) continue;
            vis[i] = true; cur++; comp[i] = cur; dfs2(i);
        }
        scccoins = new long[n];
        for (int i = 0; i < n; i++) {
            scccoins[comp[i]] += coins[i];
            for (int j : adj[i]) {
                if (comp[i] == comp[j]) continue;
                sccadj[comp[i]].add(comp[j]);
            }
        }
        dp = new long[n];
        for (int i = 0; i < n; i++) {
            dp[i] += scccoins[i];
            for (int j : sccadj[i]) dp[j] = Math.max(dp[j], dp[i]);
        }
        long ans = 0;
        for (long i : dp) ans = Math.max(ans, i);
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
