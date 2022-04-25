// created: 04-21-2022 Thu 10:24 PM

import java.util.*;
import java.io.*;

public class j_1669F {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) a[i] = io.nextInt();
            int ans = 0, r = n-1;
            int lt = 0, rt = 0;
            for (int l = 0; l <= r; l++) {
                lt += a[l];
                while (rt < lt && r > l) {
                    rt += a[r];
                    r--;
                }
                if (lt == rt) ans = n - r + l;
            }
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
