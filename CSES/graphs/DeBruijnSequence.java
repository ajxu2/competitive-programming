// created: 01-26-2024 Fri 09:56 AM

import java.util.*;
import java.io.*;

public class DeBruijnSequence {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        if (n == 1) {
            io.println(10);
            io.close();
            return;
        }
        Queue<Integer>[] adj = new Queue[1<<(n-1)]; // :skull:
        for (int i = 0; i < 1<<(n-1); i++) adj[i] = new ArrayDeque<Integer>();
        int mask = (1 << (n-1)) - 1;
        for (int i = 0; i < 1<<(n-1); i++) {
            adj[i].offer(i<<1 & mask); adj[i].offer((i<<1 ^ 1) & mask);
        }
        Deque<Integer> todo = new ArrayDeque<>(); // stack
        List<Integer> ans = new ArrayList<>();
        todo.push(0);
        while (!todo.isEmpty()) {
            int p = todo.pop();
            ans.add(p);
            // find cycle from p
            List<Integer> cycle = new ArrayList<>();
            while (true) {
                // get next
                if (adj[p].size() == 0) break;
                int nxt = adj[p].poll();
                cycle.add(nxt);
                p = nxt;
            }
            Collections.reverse(cycle);
            for (int i : cycle) todo.push(i);
        }
        io.print("0".repeat(n-2));
        for (int i : ans) io.print(i & 1);
        io.println();
        io.close();
    }
}

// credits to usaco.guide team for this template
class FastIO extends PrintWriter {
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
