// created: 01-13-2024 Sat 11:09 PM

import java.util.*;
import java.io.*;

public class FlightRoutes {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt(), k = io.nextInt();
        List<Pair>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<Pair>();
        for (int i = 0; i < m; i++) {
            int a = io.nextInt() - 1, b = io.nextInt() - 1, w = io.nextInt();
            adj[a].add(new Pair(w, b));
        }
        long[] d = new long[n];
        Arrays.fill(d, (long)1e18);
        int[] cnt = new int[n];
        Queue<Pair> pq = new PriorityQueue<>(); pq.offer(new Pair(0, 0));
        List<Long> ans = new ArrayList<>();
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            // found new path to p.s
            if (cnt[p.s] == k) continue;
            cnt[p.s]++;
            if (p.s == n-1) ans.add(p.f);
            for (Pair i : adj[p.s]) {
                pq.offer(new Pair(p.f + i.f, i.s));
            }
        }
        for (int i = 0; i < k; i++) {
            io.print(ans.get(i));
            io.print(i == k-1 ? "\n" : " ");
        }
        io.close();
    }
}

class Pair implements Comparable<Pair> {
    long f; int s;
    public Pair(long f, int s) {
        this.f = f; this.s = s;
    }
    public int compareTo(Pair p) {
        if (f == p.f) return Integer.compare(s, p.s);
        return Long.compare(f, p.f);
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
