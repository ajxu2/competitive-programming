// created: 04-21-2022 Thu 10:42 PM

import java.util.*;
import java.io.*;

public class j_1669H {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt(), k = io.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = io.nextInt();
            int[][] b = new int[n][31];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 31; j++) {
                    if ((a[i] & (1 << j)) != 0) b[i][j] = 1;
                    else b[i][j] = 0;
                }
            }
            int[] cost = new int[31];
            for (int i = 0; i < 31; i++) {
                for (int j = 0; j < n; j++) {
                    if (b[j][i] == 0) cost[i]++;
                }
            }
            for (int i = 30; i >= 0; i--) {
                if (k >= cost[i]) {
                    k -= cost[i]; cost[i] = 0;
                }
            }
            int ans = 0;
            for (int i = 0; i < 31; i++) {
                if (cost[i] == 0) ans += (1 << i);
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
