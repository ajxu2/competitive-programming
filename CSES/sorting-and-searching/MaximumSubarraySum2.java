// created: 01-07-2024 Sun 09:54 PM

import java.util.*;
import java.io.*;

public class MaximumSubarraySum2 {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), x = io.nextInt(), y = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        long[] p = new long[n]; p[0] = a[0];
        for (int i = 1; i < n; i++) p[i] = p[i-1] + a[i];
        long ans = p[x-1], mn = 0;
        for (int i = x; i < y; i++) {
            mn = Math.min(mn, p[i-x]);
            ans = Math.max(ans, p[i] - mn);
        }
        // sliding window min of [i-y, i-x]
        Deque<Integer> dq = new ArrayDeque<>(); // yay deques!
        for (int i = 0; i <= y-x; i++) {
            while (!dq.isEmpty() && p[dq.peekLast()] > p[i]) dq.pollLast();
            dq.offerLast(i);
        }
        for (int i = y; i < n; i++) {
            // extract answer
            ans = Math.max(ans, p[i] - p[dq.peekFirst()]);
            // update deque
            while (!dq.isEmpty() && p[dq.peekLast()] > p[i-x+1]) dq.pollLast();
            dq.offerLast(i-x+1);
            if (dq.peekFirst() == i-y) dq.pollFirst();
        }
        io.println(ans);
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
