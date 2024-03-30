// created: 03-29-2024 Fri 09:48 PM

import java.util.*;
import java.io.*;

public class MovingRobots {
    static FastIO io = new FastIO();
    static final int[] dx = new int[]{1, 0, -1, 0}, dy = new int[]{0, 1, 0, -1};
    static boolean valid(int x) { return x >= 0 && x < 8; }
    static boolean valid(int x, int y) { return valid(x) && valid(y); }
    public static void main(String[] args) throws IOException {
        int k = io.nextInt();
        double[][][][][] a = new double[8][8][k+1][8][8]; // :eateot:
        // a[x1][y1][i][x2][y2] = after i steps, prob that (x1, y1) is at (x2, y2)
        for (int xi = 0; xi < 8; xi++) for (int yi = 0; yi < 8; yi++) a[xi][yi][0][xi][yi] = 1;
        for (int xi = 0; xi < 8; xi++) {
            for (int yi = 0; yi < 8; yi++) {
                for (int steps = 0; steps < k; steps++) {
                    for (int xf = 0; xf < 8; xf++) {
                        for (int yf = 0; yf < 8; yf++) {
                            List<int[]> poss = new ArrayList<>();
                            for (int i = 0; i < 4; i++) {
                                int nx = xf + dx[i], ny = yf + dy[i];
                                if (valid(nx, ny)) poss.add(new int[]{nx, ny});
                            }
                            for (int[] i : poss) a[xi][yi][steps+1][i[0]][i[1]] += a[xi][yi][steps][xf][yf] / poss.size();
                        }
                    }
                }
            }
        }
        double ans = 0;
        for (int xf = 0; xf < 8; xf++) {
            for (int yf = 0; yf < 8; yf++) {
                double prod = 1;
                for (int xi = 0; xi < 8; xi++) {
                    for (int yi = 0; yi < 8; yi++) {
                        prod *= 1 - a[xi][yi][k][xf][yf];
                    }
                }
                ans += prod;
            }
        }
        io.printf("%.6f%n", ans);
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
