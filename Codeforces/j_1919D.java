// created: 01-06-2024 Sat 10:54 AM

import java.util.*;
import java.io.*;

public class j_1919D {
    static FastIO io = new FastIO();
    static int[] a;
    static ArrayList<Integer>[] pos;
    static boolean uwu(int x, int y, int r) {
        // idea: "collapse" 0 paths
        // is it possible to make trees from a[x:y] if roots have depth r
        if (x > y) return true;
        if (x == y) {
            if (a[x] == r) return true;
            return false;
        }
        // get occurrences of r
        ArrayList<Integer> rs = new ArrayList<>();
        int idx = Collections.binarySearch(pos[r], x);
        if (idx < 0) idx = -idx - 1;
        while (idx < pos[r].size() && pos[r].get(idx) <= y) {
            rs.add(pos[r].get(idx)); idx++;
        }
        if (rs.size() == 0) return false;
        else {
            boolean ans = uwu(x, rs.getFirst()-1, r+1) && uwu(rs.getLast()+1, y, r+1);
            for (int i = 0; i < rs.size()-1; i++) ans &= uwu(rs.get(i)+1, rs.get(i+1)-1, r+1);
            return ans;
        }
    }
    static void solve() {
        int n = io.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        pos = new ArrayList[n];
        for (int i = 0; i < n; i++) pos[i] = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) pos[a[i]].add(i);
        if (pos[0].size() == 1 && uwu(0, n-1, 0)) io.println("YES");
        else io.println("NO");
    }
    public static void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
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
