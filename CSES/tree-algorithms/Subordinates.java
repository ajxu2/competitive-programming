// created: 02-20-2024 Tue 02:21 PM
 
import java.util.*;
import java.io.*;
 
public class Subordinates {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        List<Integer>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
        for (int i = 1; i < n; i++) {
            int u = io.nextInt() - 1;
            adj[u].add(i);
        }
        Queue<Integer> q = new ArrayDeque<>();
        List<Integer> order = new ArrayList<>();
        q.offer(0);
        while (!q.isEmpty()) {
            int p = q.poll();
            order.add(p);
            for (int i : adj[p]) q.offer(i);
        }
        Collections.reverse(order);
        int[] ans = new int[n];
        for (int i : order) {
            for (int j : adj[i]) ans[i] += ans[j] + 1;
        }
        for (int i = 0; i < n; i++) {
            io.print(ans[i]);
            io.print(i == n-1 ? "\n" : " ");
        }
        io.close();
    }
}
 
class FastIO extends PrintWriter {
    private String[] st = new String[0];
    private int stptr = 0;
    private BufferedReader br;
    public FastIO() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    public String next() throws IOException {
        while (stptr == st.length) {
            st = br.readLine().split("\\s+");
            stptr = 0;
        }
        return st[stptr++];
    }
    public int nextInt() throws IOException { return Integer.parseInt(next()); }
    public long nextLong() throws IOException { return Long.parseLong(next()); }
}
