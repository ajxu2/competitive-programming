// created: 04-07-2022 Thu 12:27 AM

import java.util.*;
import java.io.*;

public class BuildingTeams {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Integer> adj[] = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt();
            adj[a].add(b); adj[b].add(a);
        }
        int color[] = new int[n+1];
        boolean works = true;
        for (int i = 1; i <= n; i++) {
            if (color[i] != 0) continue;
            Queue<Integer> q = new LinkedList<>();
            q.add(i); color[i] = 1;
            while (!q.isEmpty()) {
                int process = q.remove();
                for (int j : adj[process]) {
                    if (color[j] == 0) {
                        color[j] = 3 - color[process];
                        q.add(j);
                    } else if (color[j] == color[process]) {
                        works = false;
                    }
                }
            }
        }
        if (!works) io.println("IMPOSSIBLE");
        else {
            for (int i = 1; i <= n; i++) io.print(color[i]+" ");
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
