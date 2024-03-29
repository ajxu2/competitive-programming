// created: 03-24-2024 Sun 03:57 PM

import java.util.*;
import java.io.*;

public class PathQueries2 {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        int[] vals = new int[n];
        for (int i = 0; i < n; i++) vals[i] = io.nextInt();
        int[] head = new int[n], to = new int[2*n-2], nxt = new int[2*n-2];
        Arrays.fill(head, -1);
        for (int i = 0; i < n-1; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            to[2*i] = v; nxt[2*i] = head[u]; head[u] = 2*i;
            to[2*i+1] = u; nxt[2*i+1] = head[v]; head[v] = 2*i+1;
        }
        // get DFS order
        int[] dfsOrder = new int[n], par = new int[n], depth = new int[n];
        Arrays.fill(par, -1);
        int timer = 0;
        Deque<Integer> dfs = new ArrayDeque<>();
        par[0] = -1; depth[0] = 0; dfs.push(0);
        while (!dfs.isEmpty()) {
            int cur = dfs.pop();
            dfsOrder[timer++] = cur;
            for (int whar = head[cur]; whar != -1; whar = nxt[whar]) {
                int i = to[whar];
                if (i == par[cur]) continue;
                par[i] = cur; depth[i] = depth[cur] + 1; dfs.push(i);
            }
        }
        int[] subtreeSize = new int[n]; Arrays.fill(subtreeSize, 1);
        for (int i = n-1; i >= 0; i--) {
            int cur = dfsOrder[i];
            for (int whar = head[cur]; whar != -1; whar = nxt[whar]) {
                int j = to[whar];
                if (j == par[cur]) continue;
                subtreeSize[cur] += subtreeSize[j];
            }
        }
        // do HLD with DFS
        int[] hldPar = new int[n], hldPos = new int[n];
        Arrays.fill(hldPar, -1); hldPar[0] = 0;
        timer = 0; dfs.push(0);
        while (!dfs.isEmpty()) {
            int cur = dfs.pop();
            hldPos[cur] = timer++;
            int heavySon = -1, heavyWeight = -1;
            for (int whar = head[cur]; whar != -1; whar = nxt[whar]) {
                int i = to[whar];
                if (i == par[cur]) continue;
                if (subtreeSize[i] > heavyWeight) {
                    heavySon = i;
                    heavyWeight = subtreeSize[i];
                }
            }
            if (heavySon == -1) continue; // reached leaf
            for (int whar = head[cur]; whar != -1; whar = nxt[whar]) {
                int i = to[whar];
                if (i == par[cur] || i == heavySon) continue;
                hldPar[i] = i; dfs.push(i);
            }
            hldPar[heavySon] = hldPar[cur]; dfs.push(heavySon);
        }
        int[] hldArray = new int[n];
        for (int i = 0; i < n; i++) hldArray[hldPos[i]] = vals[i];
        Segtree seg = new Segtree(hldArray);
        StringBuilder out = new StringBuilder();
        while (q --> 0) {
            int type = io.nextInt();
            if (type == 1) seg.upd(hldPos[io.nextInt() - 1], io.nextInt());
            else {
                int u = io.nextInt() - 1, v = io.nextInt() - 1;
                int ans = 0;
                int cntr = 0;
                while (hldPar[u] != hldPar[v]) {
                    // make u have deeper parent
                    if (depth[hldPar[u]] < depth[hldPar[v]]) {
                        u ^= v; v ^= u; u ^= v;
                    }
                    // advance
                    ans = Math.max(ans, seg.qry(hldPos[hldPar[u]], hldPos[u]));
                    u = par[hldPar[u]];
                }
                if (depth[u] > depth[v]) {
                    u ^= v; v ^= u; u ^= v;
                }
                ans = Math.max(ans, seg.qry(hldPos[u], hldPos[v]));
                out.append(ans).append(' ');
            }
        }
        io.println(out);
        io.close();
    }
}

class Segtree {
    public int n;
    public int[] tree;
    public int cmb(int a, int b) { return Math.max(a, b); }
    public final int id = Integer.MIN_VALUE;
    public Segtree(int n) {
        this.n = 1;
        while (this.n < n) this.n <<= 1;
        tree = new int[this.n << 1];
        Arrays.fill(tree, id);
    }
    public Segtree(int[] a) {
        this(a.length);
        for (int i = 0; i < a.length; i++) tree[i + n] = a[i];
        for (int i = n - 1; i > 0; i--) tree[i] = cmb(tree[i << 1], tree[i << 1 ^ 1]);
    }
    public void upd(int i, int x) {
        i += n;
        tree[i] = x; i >>= 1;
        for (; i > 0; i >>= 1) tree[i] = cmb(tree[i << 1], tree[i << 1 ^ 1]);
    }
    public int qry(int l, int r) {
        l += n; r += n;
        int res = id;
        while (l <= r) {
            if ((l & 1) == 1) res = cmb(res, tree[l++]);
            if ((r & 1) == 0) res = cmb(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
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
