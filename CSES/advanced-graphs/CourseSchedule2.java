// created: 05-06-2024 Mon 12:43 AM

import java.util.*;
import java.io.*;

public class CourseSchedule2 {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        int[] head = new int[n], to = new int[m], nxt = new int[m], in = new int[n];
        Arrays.fill(head, -1);
        for (int i = 0; i < m; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            to[i] = u; nxt[i] = head[v]; head[v] = i;
            in[u]++;
        }
        int[] topo = new int[n];
        int ptr = n - 1;
        Queue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0; i < n; i++) if (in[i] == 0) q.offer(i);
        while (!q.isEmpty()) {
            int p = q.poll();
            topo[ptr--] = p;
            for (int whar = head[p]; whar != -1; whar = nxt[whar]) {
                int i = to[whar];
                if (--in[i] == 0) q.offer(i);
            }
        }
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < n; i++) out.append(topo[i] + 1).append(i == n-1 ? '\n' : ' ');
        io.print(out);
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
