// created: 02-29-2024 Thu 10:53 AM

import java.util.*;
import java.io.*;

public class CountingPaths {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        List<Integer>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            adj[u].add(v); adj[v].add(u);
        }
        // construct euler tour (janky)
        int[] ptr = new int[n];
        Deque<Integer> dfs = new ArrayDeque<>(); // stack
        dfs.push(0);
        int[] euler = new int[2*n-1], depth = new int[n], par = new int[n];
        int timer = 0;
        while (!dfs.isEmpty()) {
            int cur = dfs.peek();
            euler[timer] = cur; timer++;
            if (ptr[cur] >= adj[cur].size()) dfs.pop();
            else {
                int nxt = adj[cur].get(ptr[cur]);
                depth[nxt] = depth[cur] + 1;
                adj[nxt].remove(Integer.valueOf(cur));
                par[nxt] = cur;
                dfs.push(nxt);
                ptr[cur]++;
            }
        }
        int[] start = new int[n], end = new int[n];
        Arrays.fill(start, -1);
        for (int i = 0; i < 2*n-1; i++) {
            if (start[euler[i]] == -1) start[euler[i]] = i;
            end[euler[i]] = i;
        }
        State[] thing = new State[2*n-1];
        for (int i = 0; i < 2*n-1; i++) thing[i] = new State(euler[i], depth[euler[i]]);
        SparseTable lca = new SparseTable(thing);
        int[] ps = new int[2*n-1];
        for (int i = 0; i < m; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            if (start[u] > start[v]) {
                u ^= v; v ^= u; u ^= v;
            }
            int l = lca.qry(start[u], start[v]).i;
            ps[start[u]]++; ps[start[v]]++; ps[start[l]]--;
            if (l != 0) ps[start[par[l]]]--;
        }
        for (int i = 1; i < 2*n-1; i++) ps[i] += ps[i-1];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(start[i] == 0 ? ps[end[i]] : ps[end[i]] - ps[start[i] - 1]);
            sb.append(i == n-1 ? '\n' : ' ');
        }
        io.print(sb);
        io.close();
    }
}

class SparseTable {
    int n; State[][] table;
    private int log2(int x) { return 31 - Integer.numberOfLeadingZeros(x); }
    private State cmb(State x, State y) {
        if (x.compareTo(y) < 0) return x;
        else return y;
    }
    public SparseTable(State[] a) {
        n = a.length;
        table = new State[log2(n)+1][n];
        for (int i = 0; i < n; i++) table[0][i] = a[i];
        for (int i = 1; i <= log2(n); i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = cmb(table[i-1][j], table[i-1][j+(1<<i-1)]);
            }
        }
    }
    public State qry(int l, int r) {
        int lg = log2(r - l + 1);
        return cmb(table[lg][l], table[lg][r-(1<<lg)+1]);
    }
}
 
class State {
    int i, depth;
    public State(int i, int depth) {
        this.i = i; this.depth = depth;
    }
    public int compareTo(State o) {
        if (depth == o.depth) return Integer.compare(i, o.i);
        return Integer.compare(depth, o.depth);
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
