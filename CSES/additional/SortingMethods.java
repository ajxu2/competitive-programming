// created: 04-28-2024 Sun 10:53 AM

import java.util.*;
import java.io.*;

public class SortingMethods {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt() - 1;
        // 1. number of inversions
        long ans1 = 0;
        int[] bit = new int[n];
        for (int i = n-1; i >= 0; i--) {
            int val = a[i];
            for (int j = val; j >= 0; j &= j + 1, j--) ans1 += bit[j];
            for (int j = val; j < n; j |= j + 1) bit[j]++;
        }
        // 2. n - number of cycles
        int ans2 = n;
        boolean[] vis = new boolean[n];
        for (int i : a) {
            if (!vis[i]) ans2--;
            while (!vis[i]) { vis[i] = true; i = a[i]; }
        }
        // 3. n - length of LIS
        List<Integer> dp = new ArrayList<>();
        for (int i : a) {
            int idx = ~Collections.binarySearch(dp, i);
            if (idx == dp.size()) dp.add(i);
            else dp.set(idx, i);
        }
        int ans3 = n - dp.size();
        // 4. n - some position thing rofl
        int[] pos = new int[n];
        for (int i = 0; i < n; i++) pos[a[i]] = i;
        int ans4 = n - 1;
        for (int i = n-2; i >= 0 && pos[i] < pos[i+1]; i--) ans4--;
        io.println(ans1 + " " + ans2 + " " + ans3 + " " + ans4);
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
