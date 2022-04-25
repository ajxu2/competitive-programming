// created: 04-21-2022 Thu 08:57 PM

import java.util.*;
import java.io.*;

public class j_1669B {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt();
            int a[] = new int[n+1];
            for (int i = 0; i < n; i++) a[io.nextInt()]++;
            int ans = -1;
            for (int i = 1; i <= n; i++) if (a[i] >= 3) ans = i;
            io.println(ans);
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
