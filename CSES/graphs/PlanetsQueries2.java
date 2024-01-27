// created: 01-14-2024 Sun 11:33 PM

import java.util.*;
import java.io.*;

public class PlanetsQueries2 {
    static FastIO io = new FastIO();
    static int n, q;
    static List<Integer>[] adj;
    static int[] a, depth, loopidx, looplen, ccid;
    static int[][] jmp;
    static void dfs(int x) {
        // update the answer for x and its parents
        if (depth[a[x]] == -1) dfs(a[x]);
        depth[x] = depth[a[x]] + 1;
    }
    public static void main(String[] args) throws IOException {
        n = io.nextInt(); q = io.nextInt();
        adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt() - 1;
            adj[i].add(a[i]); adj[a[i]].add(i);
        }
        ccid = new int[n]; Arrays.fill(ccid, -1);
        loopidx = new int[n]; Arrays.fill(loopidx, -1);
        depth = new int[n]; Arrays.fill(depth, -1);
        looplen = new int[n]; Arrays.fill(looplen, -1);
        for (int i = 0; i < n; i++) {
            if (ccid[i] != -1) continue;
            ccid[i] = i;
            // calculate loop indices
            int tortoise = i, hare = i;
            do {
                tortoise = a[tortoise];
                hare = a[a[hare]];
            } while (tortoise != hare);
            int cnt = 0;
            do {
                loopidx[hare] = cnt;
                depth[hare] = 0;
                cnt++; hare = a[hare];
            } while (tortoise != hare);
            do {
                looplen[hare] = cnt;
                hare = a[hare];
            } while (tortoise != hare);
            // mark this CC as done
            // need BFS because java is stupid???
            Queue<Integer> qq = new ArrayDeque<>(); qq.offer(i);
            while (!qq.isEmpty()) {
                int p = qq.poll();
                for (int j : adj[p]) {
                    if (ccid[j] != -1) continue;
                    ccid[j] = i; qq.offer(j);
                }
            }
        }
        // calculate depths of tree nodes
        for (int i = 0; i < n; i++) {
            if (depth[i] == -1) dfs(i);
        }
        // calculate binary lifting
        jmp = new int[19][n]; // 1<<i after j
        jmp[0] = a;
        for (int i = 1; i < 19; i++) {
            for (int j = 0; j < n; j++) {
                jmp[i][j] = jmp[i-1][jmp[i-1][j]];
            }
        }
        // solve!!!
        for (int i = 0; i < q; i++) {
            int x = io.nextInt() - 1, y = io.nextInt() - 1;
            if (ccid[x] != ccid[y]) {
                io.println(-1);
                continue;
            }
            if (depth[x] == 0 && depth[y] == 0) { // loop -> loop
                int ans = loopidx[y] - loopidx[x];
                if (ans < 0) ans += looplen[x];
                io.println(ans);
            } else if (depth[x] == 0 && depth[y] != 0) { // loop -> tree
                io.println(-1);
            } else if (depth[x] != 0 && depth[y] == 0) { // tree -> loop
                int ans = depth[x];
                // jump x by depth[x]
                for (int j = 0; j < 19; j++) if ((depth[x] & (1 << j)) != 0) x = jmp[j][x];
                int tmp = loopidx[y] - loopidx[x];
                if (tmp < 0) tmp += looplen[x];
                ans += tmp;
                io.println(ans);
            } else { // tree -> tree
                int diff = depth[x] - depth[y];
                // jump x by diff
                for (int j = 0; j < 19; j++) if ((diff & (1 << j)) != 0) x = jmp[j][x];
                if (x == y) io.println(diff);
                else io.println(-1);
            }
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
