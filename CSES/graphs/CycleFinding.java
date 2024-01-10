// created: 01-09-2024 Tue 11:28 PM

import java.util.*;
import java.io.*;

public class CycleFinding {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        Edge[] e = new Edge[m];
        for (int i = 0; i < m; i++) {
            e[i] = new Edge();
            e[i].a = io.nextInt() - 1; e[i].b = io.nextInt() - 1; e[i].x = io.nextInt();
        }
        long[] d = new long[n];
        Arrays.fill(d, (long)1e18); d[0] = 0;
        int[] par = new int[n];
        for (int i = 0; i < n; i++) {
            for (Edge j : e) {
                if (d[j.a] + j.x < d[j.b]) {
                    d[j.b] = d[j.a] + j.x;
                    par[j.b] = j.a;
                }
            }
        }
        int st = -1;
        for (Edge i : e) {
            if (d[i.a] + i.x < d[i.b]) st = i.a;
        }
        if (st == -1) {
            // no negative cycles
            io.println("NO");
            io.close();
            return;
        }
        boolean[] vis = new boolean[n];
        while (!vis[st]) {
            vis[st] = true; st = par[st];
        }
        List<Integer> ans = new ArrayList<>();
        do {
            ans.add(st); st = par[st];
        } while (st != ans.get(0));
        Collections.reverse(ans);
        io.println("YES");
        for (int i = 0; i < ans.size(); i++) {
            io.print(ans.get(i) + 1 + " ");
        }
        io.println(ans.get(0) + 1);
        io.close();
    }
}

class Edge {
    int a, b, x;
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
