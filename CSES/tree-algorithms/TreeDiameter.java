// created: 02-25-2024 Sun 04:19 PM

import java.util.*;
import java.io.*;

public class TreeDiameter {
    static FastIO io = new FastIO();
    static List<Integer>[] adj;
    static int[] farthest(int x) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{x, -1, 0});
        int node = -1, depth = -1;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            node = p[0]; depth = p[2];
            for (int i : adj[p[0]]) {
                if (i == p[1]) continue;
                q.offer(new int[]{i, p[0], p[2] + 1});
            }
        }
        return new int[]{node, depth};
    }
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            adj[u].add(v); adj[v].add(u);
        }
        int a = farthest(0)[0];
        io.println(farthest(a)[1]);
        io.close();
    }
}

class Pair {
    int f, s;
    public Pair(int f, int s) {
        this.f = f; this.s = s;
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
