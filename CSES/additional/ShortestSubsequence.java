// created: 04-09-2024 Tue 07:20 PM

import java.util.*;
import java.io.*;

public class ShortestSubsequence {
    static FastIO io = new FastIO();
    static final char[] mp = new char[]{'A', 'C', 'G', 'T'};
    public static void main(String[] args) throws IOException {
        String s = io.next(); int n = s.length();
        // the code below looks very mysterious
        // it's actually just calculating shortest path in a DAG :)
        int[] dp = new int[n+1], par = new int[n+1], ptr = new int[4];
        Arrays.fill(dp, Integer.MAX_VALUE); Arrays.fill(par, -1);
        for (int i = 0; i < 4; i++) {
            while (ptr[i] < n && s.charAt(ptr[i]) != mp[i]) ptr[i]++;
            if (ptr[i] == n) {
                io.println(mp[i]);
                io.close();
                return;
            }
            dp[ptr[i]] = 0;
        }
        char lst = '?';
        for (int i = 0; i < n; i++) {
            int idx = Arrays.binarySearch(mp, s.charAt(i)); // lol
            do {
                ptr[idx]++;
            } while (ptr[idx] < n && s.charAt(ptr[idx]) != mp[idx]);
            for (int j = 0; j < 4; j++) {
                if (dp[i] + 1 < dp[ptr[j]]) {
                    dp[ptr[j]] = dp[i] + 1;
                    par[ptr[j]] = i;
                    if (ptr[j] == n) lst = mp[j];
                }
            }
        }
        StringBuilder ans = new StringBuilder(Character.toString(lst));
        int ptr2 = par[n];
        while (ptr2 != -1) {
            ans.append(s.charAt(ptr2));
            ptr2 = par[ptr2];
        }
        io.println(ans.reverse());
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
