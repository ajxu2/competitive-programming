// created: 06-02-2022 Thu 05:02 PM

import java.util.*;
import java.io.*;

public class CowNavigation {
    static final int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO("cownav.in", "cownav.out");
        int n = io.nextInt();
        boolean a[][] = new boolean[n+2][n+2]; // true for empty
        for (int i = 1; i <= n; i++) {
            String s = io.next();
            for (int j = 0; j < n; j++) {
                if (s.charAt(j) == 'E') a[i][j+1] = true;
            }
        }
        int dist[][][][][][] = new int[n+2][n+2][4][n+2][n+2][4]; // wtf
        for (int q = 0; q <= n+1; q++)
            for (int w = 0; w <= n+1; w++)
                for (int e = 0; e < 4; e++)
                    for (int r = 0; r <= n+1; r++)
                        for (int t = 0; t <= n+1; t++)
                            for (int y = 0; y < 4; y++) dist[q][w][e][r][t][y] = -1;
        Queue<State> q = new LinkedList<>();
        q.add(new State(n, 1, 1, n, 1, 2)); dist[n][1][1][n][1][2] = 0;
        while (!q.isEmpty()) {
            State p = q.remove();
            // forward
            State tmp = new State(p.x1, p.y1, p.d1, p.x2, p.y2, p.d2);
            tmp.x1 += dx[tmp.d1]; tmp.y1 += dy[tmp.d1]; tmp.x2 += dx[tmp.d2]; tmp.y2 += dy[tmp.d2];
            if (!a[tmp.x1][tmp.y1] || (p.x1 == 1 && p.y1 == n)) {
                tmp.x1 -= dx[tmp.d1]; tmp.y1 -= dy[tmp.d1];
            }
            if (!a[tmp.x2][tmp.y2] || (p.x2 == 1 && p.y2 == n)) {
                tmp.x2 -= dx[tmp.d2]; tmp.y2 -= dy[tmp.d2];
            }
            if (dist[tmp.x1][tmp.y1][tmp.d1][tmp.x2][tmp.y2][tmp.d2] == -1) {
                q.add(tmp);
                dist[tmp.x1][tmp.y1][tmp.d1][tmp.x2][tmp.y2][tmp.d2] = dist[p.x1][p.y1][p.d1][p.x2][p.y2][p.d2] + 1;
            }
            // turn cw
            tmp = new State(p.x1, p.y1, p.d1, p.x2, p.y2, p.d2);
            tmp.d1 = (tmp.d1+3)%4; tmp.d2 = (tmp.d2+3)%4;
            if (dist[tmp.x1][tmp.y1][tmp.d1][tmp.x2][tmp.y2][tmp.d2] == -1) {
                q.add(tmp);
                dist[tmp.x1][tmp.y1][tmp.d1][tmp.x2][tmp.y2][tmp.d2] = dist[p.x1][p.y1][p.d1][p.x2][p.y2][p.d2] + 1;
            }
            // turn ccw
            tmp = new State(p.x1, p.y1, p.d1, p.x2, p.y2, p.d2);
            tmp.d1 = (tmp.d1+1)%4; tmp.d2 = (tmp.d2+1)%4;
            if (dist[tmp.x1][tmp.y1][tmp.d1][tmp.x2][tmp.y2][tmp.d2] == -1) {
                q.add(tmp);
                dist[tmp.x1][tmp.y1][tmp.d1][tmp.x2][tmp.y2][tmp.d2] = dist[p.x1][p.y1][p.d1][p.x2][p.y2][p.d2] + 1;
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (dist[1][n][i][1][n][j] == -1) continue;
                ans = Math.min(ans, dist[1][n][i][1][n][j]);
            }
        }
        io.println(ans);
        io.close();
    }
    static class State {
        public int x1, y1, d1, x2, y2, d2;
        public State(int x1, int y1, int d1, int x2, int y2, int d2) {
            this.x1 = x1; this.y1 = y1; this.d1 = d1; this.x2 = x2; this.y2 = y2; this.d2 = d2;
        }
        public String toString() {
            return x1+" "+y1+" "+d1+" "+x2+" "+y2+" "+d2;
        }
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
