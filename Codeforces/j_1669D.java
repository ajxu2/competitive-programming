// created: 04-21-2022 Thu 09:02 PM

import java.util.*;
import java.io.*;

public class j_1669D {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt();
            String s = io.next();
            String[] t = s.split("W");
            boolean works = true;
            for (String i : t) {
                if (i.equals("")) continue;
                char tmp = i.charAt(0);
                boolean allSame = true;
                for (int j = 0; j < i.length(); j++) {
                    if (i.charAt(j) != tmp) allSame = false;
                }
                if (allSame) works = false;
            }
            if (works) io.println("YES");
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
