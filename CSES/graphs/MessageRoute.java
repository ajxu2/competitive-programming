// created: 04-07-2022 Thu 10:16 PM

import java.util.*;
import java.io.*;

public class MessageRoute {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Integer> adj[] = new ArrayList[n+1];
        for (int i = 0; i <= n; i++) adj[i] = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt();
            adj[a].add(b); adj[b].add(a);
        }
        boolean vis[] = new boolean[n+1];
        int par[] = new int[n+1];
        Queue<Integer> q = new LinkedList<>();
        q.add(1); vis[1] = true;
        boolean works = false;
        while (!q.isEmpty()) {
            Integer process = q.remove();
            if (process == n) works = true;
            for (int i : adj[process]) {
                if (vis[i]) continue;
                q.add(i); vis[i] = true; par[i] = process;
            }
        }
        if (!works) io.println("IMPOSSIBLE");
        else {
            ArrayList<Integer> ans = new ArrayList<>();
            int x = n;
            while (x != 1) {
                ans.add(x);
                x = par[x];
            }
            ans.add(1);
            Collections.reverse(ans);
            io.println(ans.size());
            for (int i : ans) io.print(i+" ");
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
