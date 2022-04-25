// created: 04-23-2022 Sat 04:23 PM

import java.util.*;
import java.io.*;

public class StaticRangeSum {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt(), q = io.nextInt();
        long a[] = new long[n+1];
        for (int i = 1; i <= n; i++) a[i] = io.nextLong();
        for (int i = 1; i <= n; i++) a[i] += a[i-1];
        for (int i = 0; i < q; i++) {
            int x = io.nextInt(), y = io.nextInt();
            io.println(a[y] - a[x-1]);
        }
        io.close();
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
