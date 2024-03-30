// created: 03-29-2024 Fri 12:54 PM

import java.util.*;
import java.io.*;

public class ReachableNodes {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        int[] head = new int[n], to = new int[m], nxt = new int[m], in = new int[n];
        Arrays.fill(head, -1);
        for (int i = 0; i < m; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            to[i] = v; nxt[i] = head[u]; head[u] = i; in[v]++;
        }
        int[] topo = new int[n];
        int timer = n-1;
        Queue<Integer> bfs = new ArrayDeque<>();
        for (int i = 0; i < n; i++) if (in[i] == 0) bfs.offer(i);
        while (!bfs.isEmpty()) {
            int cur = bfs.poll();
            topo[timer--] = cur;
            for (int whar = head[cur]; whar != -1; whar = nxt[whar]) {
                int i = to[whar];
                if (--in[i] == 0) bfs.offer(i);
            }
        }
        BitSet[] reachable = new BitSet[n];
        int[] ans = new int[n];
        for (int i : topo) {
            reachable[i] = new BitSet();
            reachable[i].set(i);
            for (int whar = head[i]; whar != -1; whar = nxt[whar]) {
                int j = to[whar];
                reachable[i].or(reachable[j]);
            }
            ans[i] = reachable[i].cardinality();
        }
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < n; i++) out.append(ans[i]).append(i == n-1 ? '\n' : ' ');
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
