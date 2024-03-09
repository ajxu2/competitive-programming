// created: 02-26-2024 Mon 02:25 PM

import java.util.*;
import java.io.*;

public class DistinctColors {
    static FastIO io = new FastIO();
    static Random r = new Random();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) c[i] = io.nextInt();
        // compress colors
        int[] sortedc = Arrays.copyOf(c, n);
        ruffleSort(sortedc);
        for (int i = 0; i < n; i++) c[i] = Arrays.binarySearch(sortedc, c[i]);
        // read in adj list (chinese edge representation)
        int[] head = new int[n], to = new int[2*n-2], nxt = new int[2*n-2];
        Arrays.fill(head, -1);
        for (int i = 0; i < n-1; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            // add edge u -> v
            to[2*i] = v; nxt[2*i] = head[u]; head[u] = 2*i;
            // add edge v -> u
            to[2*i+1] = u; nxt[2*i+1] = head[v]; head[v] = 2*i+1;
        }
        // euler tour
        int[] euler = new int[n], start = new int[n], end = new int[n];
        int timer = 0;
        Arrays.fill(start, -1); Arrays.fill(end, -1);
        Deque<Pair> dfs = new ArrayDeque<>();
        dfs.push(new Pair(0, -1));
        while (!dfs.isEmpty()) {
            int cur = dfs.peek().f, par = dfs.peek().s;
            if (start[cur] == -1) {
                start[cur] = timer;
                euler[timer] = c[cur];
                timer++;
                for (int whar = head[cur]; whar != -1; whar = nxt[whar]) {
                    int i = to[whar];
                    if (i == par) continue;
                    dfs.push(new Pair(i, cur));
                }
            } else {
                end[cur] = timer - 1;
                dfs.pop();
            }
        }
        // start and end now represent our distinct values queries
        List<Pair>[] queries = new List[n];
        for (int i = 0; i < n; i++) queries[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) queries[end[i]].add(new Pair(start[i], i));
        int[] ans = new int[n];
        int[] lst = new int[n]; Arrays.fill(lst, -1);
        BIT bit = new BIT(n);
        for (int i = 0; i < n; i++) {
            if (lst[euler[i]] != -1) bit.add(lst[euler[i]], -1);
            lst[euler[i]] = i; bit.add(i, 1);
            for (Pair j : queries[i]) ans[j.s] = (int)bit.qry(j.f, i);
        }
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < n; i++) {
            out.append(ans[i]).append(i == n-1 ? "\n" : " ");
        }
        io.print(out);
        io.close();
    }
    static void ruffleSort(int[] a) {
        for (int i = a.length - 1; i >= 1; i--) {
            int swp = r.nextInt(i+1);
            int tmp = a[swp]; a[swp] = a[i]; a[i] = tmp;
        }
        Arrays.sort(a);
    }
}

class Pair {
    public int f, s;
    public Pair(int f, int s) {
        this.f = f;
        this.s = s;
    }
}

class BIT {
    public int n;
    public long[] a, tree;
    public BIT(int n) {
        this.n = n;
        a = new long[n];
        tree = new long[n];
    }
    public void add(int i, long v) {
        a[i] += v;
        for (; i < n; i |= i + 1) tree[i] += v;
    }
    public void upd(int i, long v) { add(i, v - a[i]); }
    public long qry(int i) {
        long res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    public long qry(int i, int j) { return qry(j) - qry(i-1); }
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
