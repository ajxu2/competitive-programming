// created: 06-07-2022 Tue 11:59 AM

import java.util.*;
import java.io.*;

public class RoundTrip2 {
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt(), m = io.nextInt();
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        int[] state = new int[n+1]; // 0 = not processed, 1 = processing, 2 = done
        int[] par = new int[n+1];
        for (int i = 0; i < m; i++) {
            int a = io.nextInt(), b = io.nextInt();
            adj[a].add(b);
        }
        boolean done = false;
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (state[i] != 0) continue;
            Stack<Integer> s = new Stack<>();
            s.push(i); par[i] = -1;
            while (!s.empty()) {
                int process = s.peek();
                if (state[process] == 1) {
                    state[process] = 2;
                    s.pop();
                    continue;
                }
                state[process] = 1;
                for (int j : adj[process]) {
                    if (state[j] == 1) {
                        // found cycle!
                        par[j] = process;
                        ans.add(j);
                        done = true;
                    } else if (state[j] == 0) {
                        par[j] = process;
                        s.push(j);
                    }
                    if (done) break;
                }
                if (done) break;
            }
            if (done) break;
        }
        if (ans.size() == 0) io.println("IMPOSSIBLE");
        else {
            int orig = ans.get(0), x = orig;
            do {
                x = par[x];
                ans.add(x);
            } while (x != orig);
            Collections.reverse(ans);
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
