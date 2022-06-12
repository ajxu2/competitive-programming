// created: 06-12-2022 Sun 12:25 PM

import java.util.*;
import java.io.*;

public class FlightDiscount {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Pair<Integer, Integer>>[] adj = new ArrayList[n+1], badj = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>(); badj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt(), w = io.nextInt();
            adj[a].add(new Pair(b, w)); badj[b].add(new Pair(a, w));
        }
        long[] adjd = dijk(adj, 1), badjd = dijk(badj, n);
        long ans = Long.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            for (Pair<Integer, Integer> j : adj[i]) {
                ans = Math.min(ans, adjd[i]+badjd[j.f]+j.s/2);
            }
        }
        io.println(ans);
        io.close();
    }
    static class Pair<K, V> {
        public K f; public V s;
        public Pair(K f, V s) {
            this.f = f; this.s = s;
        }
    }
    static long[] dijk(ArrayList<Pair<Integer, Integer>>[] adj, int node) {
        long[] dist = new long[adj.length];
        Arrays.fill(dist, 1000000000000000000L); dist[node] = 0;
        PriorityQueue<Pair<Long, Integer>> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x.f));
        pq.add(new Pair<>(0L, node));
        while (!pq.isEmpty()) {
            Pair<Long, Integer> process = pq.remove();
            if (process.f > dist[process.s]) continue;
            for (Pair<Integer, Integer> i : adj[process.s]) {
                if (dist[process.s] + i.s < dist[i.f]) {
                    dist[i.f] = dist[process.s] + i.s;
                    pq.add(new Pair<>(dist[i.f], i.f));
                }
            }
        }
        return dist;
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
