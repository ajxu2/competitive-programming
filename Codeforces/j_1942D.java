// created: 03-30-2024 Sat 11:19 AM

import java.util.*;
import java.io.*;

public class j_1942D {
    static FastIO io = new FastIO();
    static void solve() {
        int n = io.nextInt(), k = io.nextInt();
        int[][] a = new int[n][n]; // (end, start) bc yay cache
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                a[j][i] = io.nextInt();
            }
        }
        /*
        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                a[i][j] = Math.max(a[i][j], a[i][j+1]);
            }
        }
        */
        int[][] dp = new int[n][k+1]; // k largest before i
        for (int i = 0; i < n; i++) for (int j = 0; j < k+1; j++) dp[i][j] = (int)-2e9;
        dp[0][0] = a[0][0]; dp[0][1] = 0;
        if (dp[0][0] < dp[0][1]) {
            dp[0][0] ^= dp[0][1];
            dp[0][1] ^= dp[0][0];
            dp[0][0] ^= dp[0][1];
        }
        for (int i = 1; i < n; i++) {
            List<Integer> candidates = new ArrayList<>();
            for (int j = 0; j < k; j++) candidates.add(dp[i-1][j]);
            candidates.add(a[i][1]); candidates.add(a[i][0]);
            // other candidates are a[i][i-j] + dp[i-j-2] for k in [0, i]
            int[] ptr = new int[n];
            Queue<Pair> pq = new PriorityQueue<>(Comparator.reverseOrder());
            for (int j = 2; j <= i; j++) pq.offer(new Pair(a[i][j] + dp[j-2][0], j));
            if (!pq.isEmpty()) {
                for (int j = 0; j < k; j++) {
                    Pair cur = pq.poll();
                    candidates.add(cur.f);
                    ptr[cur.s]++;
                    if (ptr[cur.s] == k) continue;
                    pq.offer(new Pair(a[i][cur.s] + dp[cur.s-2][ptr[cur.s]], cur.s));
                }
            }
            Collections.sort(candidates, Comparator.reverseOrder());
            for (int j = 0; j < k; j++) dp[i][j] = candidates.get(j);
        }
        for (int i = 0; i < k; i++) io.print(dp[n-1][i] + " ");
        io.println();
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
        io.close();
    }
}

class Pair implements Comparable<Pair> {
    int f, s;
    public Pair(int f, int s) {
        this.f = f; this.s = s;
    }
    public int compareTo(Pair o) {
        if (f == o.f) return Integer.compare(s, o.s);
        return Integer.compare(f, o.f);
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
