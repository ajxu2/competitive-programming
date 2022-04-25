// created: 04-24-2022 Sun 01:09 PM

import java.util.*;
import java.io.*;

// Please, never set a problem like this again.

public class j_1163C2 {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt();
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++) {
            Pair tmp = new Pair(io.nextInt(), io.nextInt());
            a[i] = tmp;
        }
        TreeMap<Pair, TreeSet<Pair>> m = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                Pair slope = new Pair(a[j].s - a[i].s, a[j].f - a[i].f);
                int reduce = gcd(slope.f, slope.s);
                if (reduce != 0) {
                    slope.f /= reduce; slope.s /= reduce;
                }
                if (slope.s < 0) {
                    slope.f *= -1; slope.s *= -1;
                }
                Pair yint;
                if (slope.s == 0) yint = new Pair(a[j].f, 1);
                else yint = new Pair(a[j].s * slope.s - slope.f * a[j].f, slope.s);
                reduce = gcd(yint.f, yint.s);
                if (reduce != 0) {
                    yint.f /= reduce; yint.s /= reduce;
                }
                if (yint.s < 0) {
                    yint.f *= -1; yint.s *= -1;
                }
                if (!m.containsKey(slope)) {
                    TreeSet<Pair> tmp = new TreeSet<>();
                    tmp.add(yint);
                    m.put(slope, tmp);
                } else m.get(slope).add(yint);
            }
        }
        long not = 0, totalPairs = 0;
        for (Pair i : m.keySet()) {
            int tmp = m.get(i).size();
            totalPairs += tmp;
            not += tmp*(tmp-1)/2;
        }
        totalPairs = totalPairs*(totalPairs-1)/2;
        io.println(totalPairs - not);
        io.close();
    }
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    static class Pair implements Comparable<Pair> {
        int f, s;
        public Pair(int f, int s) {
            this.f = f; this.s = s;
        }
        public int compareTo(Pair p) {
            if (f == p.f) return Integer.compare(s, p.s);
            return Integer.compare(f, p.f);
        }
    }
    static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;
        // standard input
        public Kattio() { this(System.in,System.out); }
        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        // USACO-style file input
        public Kattio(String problemName) throws IOException {
            super(problemName+".out");
            r = new BufferedReader(new FileReader(problemName+".in"));
        }
        // returns null if no more input
        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) {}
            return null;
        }
        public int nextInt() { return Integer.parseInt(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public long nextLong() { return Long.parseLong(next()); }
    }
}
