// created: 01-06-2024 Sat 10:56 PM

import java.util.*;
import java.io.*;

public class SumOfFourValues {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), x = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        Map<Integer, Pair> m = new HashMap<>();
        // in the below loops, we check if i and j can be the third and fourth elements
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (m.containsKey(x - a[i] - a[j])) {
                    Pair p = m.get(x - a[i] - a[j]);
                    io.println((p.f+1) + " " + (p.s+1) + " " + (i+1) + " " + (j+1));
                    io.close();
                    return;
                }
            }
            for (int j = 0; j < i; j++) m.put(a[j] + a[i], new Pair(j, i));
        }
        io.println("IMPOSSIBLE");
        io.close();
    }
}

class Pair {
    public int f, s;
    public Pair(int f, int s) {
        this.f = f; this.s = s;
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
