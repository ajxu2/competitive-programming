// created: 06-02-2022 Thu 07:58 PM

import java.util.*;
import java.io.*;

public class LasersAndMirrors {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO("lasers.in", "lasers.out");
        int n = io.nextInt();
        Pair laser = new Pair(io.nextInt(), io.nextInt()), barn = new Pair(io.nextInt(), io.nextInt());
        Pair a[] = new Pair[n];
        for (int i = 0; i < n; i++) a[i] = new Pair(io.nextInt(), io.nextInt());
        TreeMap<Pair, ArrayList<Pair>> adj = new TreeMap<>(); // second number is 69 for vertical and 420 for horizontal
        TreeMap<Pair, Integer> dist = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            if (!adj.containsKey(new Pair(a[i].f, 69))) adj.put(new Pair(a[i].f, 69), new ArrayList<>());
            if (!adj.containsKey(new Pair(a[i].s, 420))) adj.put(new Pair(a[i].s, 420), new ArrayList<>());
            adj.get(new Pair(a[i].f, 69)).add(new Pair(a[i].s, 420)); adj.get(new Pair(a[i].s, 420)).add(new Pair(a[i].f, 69));
        }
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(laser.f, 69)); q.add(new Pair(laser.s, 420));
        dist.put(new Pair(laser.f, 69), 0); dist.put(new Pair(laser.s, 420), 0);
        while (!q.isEmpty()) {
            Pair process = q.remove();
            if (!adj.containsKey(process)) continue;
            for (Pair i : adj.get(process)) {
                if (dist.containsKey(i)) continue;
                q.add(i);
                dist.put(i, dist.get(process)+1);
            }
        }
        int ans = Integer.MAX_VALUE;
        if (dist.containsKey(new Pair(barn.f, 69))) ans = dist.get(new Pair(barn.f, 69));
        if (dist.containsKey(new Pair(barn.s, 420))) ans = Math.min(ans, dist.get(new Pair(barn.s, 420)));
        if (ans == Integer.MAX_VALUE) io.println(-1);
        else io.println(ans);
        io.close();
    }
    static class Pair implements Comparable<Pair> {
        public int f, s;
        public Pair(int f, int s) {
            this.f = f; this.s = s;
        }
        public int compareTo(Pair y) {
            if (f == y.f) return Integer.compare(s, y.s);
            return Integer.compare(f, y.f);
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
