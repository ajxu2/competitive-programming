// created: 04-21-2022 Thu 09:00 PM

import java.util.*;
import java.io.*;

public class j_1669C {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) a[i] = io.nextInt();
            int par1 = a[0] % 2, par2 = a[1] % 2;
            boolean ans = true;
            for (int i = 0; i < n; i += 2) {
                if (a[i] % 2 != par1) ans = false;
            }
            for (int i = 1; i < n; i += 2) {
                if (a[i] % 2 != par2) ans = false;
            }
            if (ans) io.println("YES");
            else io.println("NO");
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
