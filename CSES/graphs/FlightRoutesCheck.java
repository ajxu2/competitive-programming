// created: 01-17-2024 Wed 11:35 PM

import java.util.*;
import java.io.*;

public class FlightRoutesCheck {
    static FastIO io = new FastIO();
    static void dfs(List<Integer>[] adj, boolean[] vis, int x) {
        for (int i : adj[x]) {
            if (vis[i]) continue;
            vis[i] = true; dfs(adj, vis, i);
        }
    }
    public static void main(String[] args) throws IOException {
        // key idea: YES iff 1 can travel to all and all can travel to 1
        // necessary: can travel between all cities -> can travel to 1 & reverse
        // sufficient: any path can go a -> 1 -> b
        int n = io.nextInt(), m = io.nextInt();
        List<Integer>[] adj = new List[n], radj = new List[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
            radj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int a = io.nextInt() - 1, b = io.nextInt() - 1;
            adj[a].add(b); radj[b].add(a);
        }
        boolean[] vis = new boolean[n];
        vis[0] = true; dfs(adj, vis, 0);
        for (int i = 0; i < n; i++) if (!vis[i]) {
            io.println("NO");
            io.println("1 " + (i + 1));
            io.close();
            return;
        }
        Arrays.fill(vis, false);
        vis[0] = true; dfs(radj, vis, 0);
        for (int i = 0; i < n; i++) if (!vis[i]) {
            io.println("NO");
            io.println((i + 1) + " 1");
            io.close();
            return;
        }
        io.println("YES");
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
