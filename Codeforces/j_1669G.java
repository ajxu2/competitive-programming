// created: 04-21-2022 Thu 10:34 PM

import java.util.*;
import java.io.*;

public class j_1669G {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt(), m = io.nextInt();
            char[][] a = new char[n+2][m+2];
            for (int i = 0; i <= n+1; i++) {
                for (int j = 0; j <= m+1; j++) {
                    a[i][j] = 'o';
                }
            }
            for (int i = 0; i < n; i++) {
                String s = io.next();
                for (int j = 0; j < m; j++) {
                    a[i+1][j+1] = s.charAt(j);
                }
            }
            for (int sim = 0; sim < 50; sim++) {
                for (int i = n; i >= 1; i--) {
                    for (int j = 1; j <= m; j++) {
                        if (a[i][j] == '*' && a[i+1][j] == '.') {
                            a[i][j] = '.';
                            a[i+1][j] = '*';
                        }
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    io.print(a[i][j]);
                }
                io.println();
            }
            io.println();
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
