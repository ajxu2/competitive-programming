// created: 04-21-2022 Thu 10:07 PM

import java.util.*;
import java.io.*;

public class j_1669E {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt();
            String[] a = new String[n];
            for (int i = 0; i < n; i++) a[i] = io.next();
            int[] tmp = new int[11];
            long ans = 0;
            for (int i = 0; i < n; i++) tmp[a[i].charAt(0)-'a']++;
            for (int i = 0; i < 11; i++) ans += (long)tmp[i]*(tmp[i]-1)/2;
            for (int i = 0; i < 11; i++) tmp[i] = 0;
            for (int i = 0; i < n; i++) tmp[a[i].charAt(1)-'a']++;
            for (int i = 0; i < 11; i++) ans += (long)tmp[i]*(tmp[i]-1)/2;
            int[] tmp2 = new int[121];
            for (int i = 0; i < n; i++) tmp2[(a[i].charAt(0)-'a')*11+(a[i].charAt(1)-'a')]++;
            for (int i = 0; i < 121; i++) ans -= (long)tmp2[i]*(tmp2[i]-1);
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
