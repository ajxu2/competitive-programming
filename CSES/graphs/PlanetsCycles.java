// created: 01-14-2024 Sun 11:08 PM

import java.util.*;
import java.io.*;

public class PlanetsCycles {
    static FastIO io = new FastIO();
    static int n;
    static List<Integer>[] adj;
    static boolean[] vis;
    static int[] a, ans;
    static void dfs(int x) {
        for (int i : adj[x]) {
            if (vis[i]) continue;
            vis[i] = true;
            dfs(i);
        }
    }
    static void dfs2(int x) {
        // update the answer for x and its parents
        if (ans[a[x]] == -1) dfs2(a[x]);
        ans[x] = ans[a[x]] + 1;
    }
    public static void main(String[] args) throws IOException {
        n = io.nextInt();
        adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt() - 1;
            adj[i].add(a[i]); adj[a[i]].add(i);
        }
        ans = new int[n];
        Arrays.fill(ans, -1);
        // calculate cycle lengths
        vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            // run Floyd's algorithm to get a cycle
            int tortoise = i, hare = i;
            do {
                tortoise = a[tortoise];
                hare = a[a[hare]];
            } while (tortoise != hare);
            // calculate cycle length
            int len = 0;
            do {
                len++;
                hare = a[hare];
            } while (tortoise != hare);
            // update answer
            do {
                ans[hare] = len;
                hare = a[hare];
            } while (tortoise != hare);
            // mark as done
            dfs(i);
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) dfs2(i);
        }
        for (int i = 0; i < n; i++) {
            io.print(ans[i]);
            io.print(i == n-1 ? "\n" : " ");
        }
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
