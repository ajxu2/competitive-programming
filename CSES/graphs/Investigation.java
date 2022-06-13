// created: 06-13-2022 Mon 10:19 AM

import java.util.*;
import java.io.*;

public class Investigation {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Pair<Integer, Integer>>[] adj = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt(), w = io.nextInt();
            adj[a].add(new Pair<>(b, w));
        }
        long[] dist = new long[n+1], num = new long[n+1], min = new long[n+1], max = new long[n+1];
        Arrays.fill(dist, 1000000000000000000L); dist[1] = 0; num[1] = 1;
        PriorityQueue<Pair<Long, Integer>> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x.f));
        pq.add(new Pair<>(0L, 1));
        while (!pq.isEmpty()) {
            Pair<Long, Integer> process = pq.remove();
            if (process.f > dist[process.s]) continue;
            for (Pair<Integer, Integer> i : adj[process.s]) {
                if (dist[process.s] + i.s < dist[i.f]) {
                    dist[i.f] = dist[process.s] + i.s;
                    num[i.f] = num[process.s]; min[i.f] = min[process.s]+1; max[i.f] = max[process.s]+1;
                    pq.add(new Pair<>(dist[i.f], i.f));
                } else if (dist[process.s] + i.s == dist[i.f]) {
                    num[i.f] += num[process.s]; num[i.f] %= 1000000007;
                    min[i.f] = Math.min(min[i.f], min[process.s]+1);
                    max[i.f] = Math.max(max[i.f], max[process.s]+1);
                }
            }
        }
        io.println(dist[n]+" "+num[n]+" "+min[n]+" "+max[n]);
        io.close();
    }
    static class Pair<K, V> {
        public K f; public V s;
        public Pair(K f, V s) {
            this.f = f; this.s = s;
        }
    }
    // credits to usaco.guide team for this template
    static class FastIO extends PrintWriter {
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
}
