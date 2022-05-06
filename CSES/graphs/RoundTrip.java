import java.util.*;
import java.io.*;
 
public class RoundTrip {
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Integer> adj[] = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt();
            adj[a].add(b); adj[b].add(a);
        }
        boolean vis[] = new boolean[n+1];
        int par[] = new int[n+1];
        boolean found = false;
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            Stack<Pair> s = new Stack<>();
            s.push(new Pair(i, -1));
            while (!s.isEmpty()) {
                Pair process = s.pop();
                vis[process.f] = true; par[process.f] = process.s;
                for (int j : adj[process.f]) {
                    if (j == process.s) continue;
                    if (vis[j]) {
                        // found cycle!!!
                        found = true;
                        par[j] = process.f;
                        ans.add(j);
                        break;
                    }
                    s.push(new Pair(j, process.f));
                }
                if (found) break;
            }
            if (found) break;
        }
        if (!found) io.println("IMPOSSIBLE");
        else {
            int orig = ans.get(0), x = par[orig];
            while (x != orig) {
                ans.add(x);
                x = par[x];
            }
            ans.add(orig);
            io.println(ans.size());
            for (int i : ans) io.print(i+" ");
            io.println();
        }
        io.close();
    }
    static class Pair {
        int f, s;
        public Pair(int f, int s) {
            this.f = f; this.s = s;
        }
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
