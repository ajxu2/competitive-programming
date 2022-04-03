// created: 03-29-2022 Tue 10:21 PM

import java.util.*;
import java.io.*;

public class j_1658A {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int T = io.nextInt();
        while (T-- > 0)  {
            int n = io.nextInt(); String s = io.next();
            ArrayList<Integer> zeroes = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '0') zeroes.add(i);
            }
            int ans = 0;
            if (zeroes.size() > 1) {
                for (int i = 1; i < zeroes.size(); i++) {
                    if (zeroes.get(i)-zeroes.get(i-1) < 3) ans += (3-zeroes.get(i)+zeroes.get(i-1));
                }
            }
            io.println(ans);
        }
        io.close();
    }
}

class Kattio extends PrintWriter {
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
