// created: 04-07-2022 Thu 10:09 PM

import java.util.*;
import java.io.*;

public class BuildingRoads {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Integer> adj[] = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt();
            adj[a].add(b); adj[b].add(a);
        }
        boolean vis[] = new boolean[n+1];
        ArrayList<Integer> reps = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            reps.add(i);
            Queue<Integer> q = new LinkedList<>();
            q.add(i); vis[i] = true;
            while (!q.isEmpty()) {
                int process = q.remove().intValue();
                for (int j : adj[process]) {
                    if (vis[j]) continue;
                    q.add(j); vis[j] = true;
                }
            }
        }
        io.println(reps.size()-1);
        for (int i = 0; i < reps.size()-1; i++) {
            io.println(reps.get(i)+" "+reps.get(i+1));
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
