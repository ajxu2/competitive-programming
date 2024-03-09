// created: 02-26-2024 Mon 11:12 AM

import java.util.*;
import java.io.*;

public class TreeDistances1 {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        List<Integer>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            adj[u].add(v); adj[v].add(u);
        }
        List<Integer> order = new ArrayList<>();
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(0);
        while (!q.isEmpty()) {
            int p = q.poll();
            order.add(p);
            for (int i : adj[p]) {
                adj[i].remove(Integer.valueOf(p));
                q.offer(i);
            }
        }
        int[] maxdepth = new int[n], maxdepthchild = new int[n], maxdepth2 = new int[n], maxup = new int[n];
        for (int idx = n-1; idx >= 0; idx--) {
            int i = order.get(idx);
            for (int j : adj[i]) {
                if (maxdepth[j] + 1 > maxdepth[i]) {
                     maxdepthchild[i] = j;
                     maxdepth[i] = maxdepth[j] + 1;
                }
            }
            for (int j : adj[i]) {
                if (maxdepthchild[i] == j) continue;
                maxdepth2[i] = Math.max(maxdepth2[i], maxdepth[j] + 1);
            }
        }
        for (int i : order) {
            for (int j : adj[i]) {
                if (maxdepthchild[i] == j) maxup[j] = Math.max(maxup[i] + 1, maxdepth2[i] + 1);
                else maxup[j] = Math.max(maxup[i] + 1, maxdepth[i] + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            io.print(Math.max(maxdepth[i], maxup[i]));
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
