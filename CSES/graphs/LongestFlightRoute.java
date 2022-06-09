// created: 06-07-2022 Tue 11:20 PM
 
import java.util.*;
import java.io.*;
 
public class LongestFlightRoute {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n+1], badj = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>(); badj[i] = new ArrayList<>();
        }
        int[] in = new int[n+1];
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt();
            adj[a].add(b); badj[b].add(a); in[b]++;
        }
        ArrayList<Integer> topo = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) q.add(i);
        }
        while (!q.isEmpty()) {
            int process = q.remove();
            topo.add(process);
            for (int j : adj[process]) {
                in[j]--;
                if (in[j] == 0) q.add(j);
            }
        }
        int[] dp = new int[n+1], par = new int[n+1];
        dp[1] = 1;
        for (int i : topo) {
            for (int j : badj[i]) {
                if (dp[j] + 1 > dp[i] && dp[j] != 0) {
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        int x = n;
        while (par[x] != 0) {
            ans.add(x);
            x = par[x];
        }
        ans.add(x);
        Collections.reverse(ans);
        if (ans.size() == 1) io.println("IMPOSSIBLE");
        else {
            io.println(ans.size());
            for (int i : ans) io.print(i+" ");
            io.println();
        }
        io.close();
    }
    // credits to usaco.guide team for this template
    static class FastIO extends PrintWriter {
        private InputStream stream;
        private byte[] buf = new byte[1<<16];
        private int curChar, numChars;
        // standard input
        public FastIO() { this(System.in,System.out); }
        public FastIO(InputStream i, OutputStream o) {
            super(o);
            stream = i;
        }
        // file input
        public FastIO(String i, String o) throws IOException {
            super(new FileWriter(o));
            stream = new FileInputStream(i);
        }
        // throws InputMismatchException() if previously detected end of file
        private int nextByte() {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars == -1) return -1; // end of file
            }
            return buf[curChar++];
        }
        // to read in entire lines, replace c <= ' '
        // with a function that checks whether c is a line break
        public String next() {
            int c; do { c = nextByte(); } while (c <= ' ');
            StringBuilder res = new StringBuilder();
            do { res.appendCodePoint(c); c = nextByte(); } while (c > ' ');
            return res.toString();
        }
        public int nextInt() {
            int c; do { c = nextByte(); } while (c <= ' ');
            int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = 10*res+c-'0';
                c = nextByte();
            } while (c > ' ');
            return res * sgn;
        }
        public long nextLong() {
            int c; do { c = nextByte(); } while (c <= ' ');
            int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = 10*res+c-'0';
                c = nextByte();
            } while (c > ' ');
            return res * sgn;
        }
        public double nextDouble() { return Double.parseDouble(next()); }
    }
}
