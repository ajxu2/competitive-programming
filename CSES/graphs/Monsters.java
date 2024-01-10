// created: 01-08-2024 Mon 11:08 PM

import java.util.*;
import java.io.*;

public class Monsters {
    static FastIO io = new FastIO();
    static int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    static char[] c = {'D', 'R', 'U', 'L'};
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), m = io.nextInt();
        boolean[][] wall = new boolean[n+2][m+2];
        // pad with wall
        for (int i = 0; i <= m+1; i++) wall[0][i] = true;
        for (int i = 0; i <= m+1; i++) wall[n+1][i] = true;
        for (int i = 0; i <= n+1; i++) wall[i][0] = true;
        for (int i = 0; i <= n+1; i++) wall[i][m+1] = true;
        State start = new State(69, 420, 1337);
        // run multisource BFS from monsters
        Queue<State> q = new ArrayDeque<>();
        int[][] d = new int[n+2][m+2];
        for (int i = 0; i <= n+1; i++) Arrays.fill(d[i], -1);
        for (int i = 1; i <= n; i++) {
            String s = io.next();
            for (int j = 1; j <= m; j++) {
                if (s.charAt(j-1) == '#') wall[i][j] = true;
                else if (s.charAt(j-1) == 'M') {
                    q.offer(new State(i, j, 0));
                    d[i][j] = 0;
                }
                else if (s.charAt(j-1) == 'A') start = new State(i, j, 0);
            }
        }
        while (!q.isEmpty()) {
            State p = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i], ny = p.y + dy[i];
                if (!wall[nx][ny] && d[nx][ny] == -1) {
                    d[nx][ny] = p.d + 1;
                    q.offer(new State(nx, ny, p.d + 1));
                }
            }
        }
        // another BFS, but from the start node
        int[][] dir = new int[n+2][m+2];
        for (int i = 0; i <= n+1; i++) Arrays.fill(dir[i], -1);
        q.offer(start);
        while (!q.isEmpty()) {
            State p = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i], ny = p.y + dy[i];
                if (!wall[nx][ny] && dir[nx][ny] == -1 && (d[nx][ny] == -1 || p.d + 1 < d[nx][ny])) {
                    dir[nx][ny] = i;
                    q.offer(new State(nx, ny, p.d + 1));
                }
            }
        }
        State end = new State(-1, -1, -1);
        for (int i = 1; i <= m; i++) if (dir[1][i] != -1) end = new State(1, i, 0);
        for (int i = 1; i <= m; i++) if (dir[n][i] != -1) end = new State(n, i, 0);
        for (int i = 1; i <= n; i++) if (dir[i][1] != -1) end = new State(i, 1, 0);
        for (int i = 1; i <= n; i++) if (dir[i][m] != -1) end = new State(i, m, 0);
        if (start.x == 1 || start.x == n || start.y == 1 || start.y == m) io.println("YES\n0");
        else if (end.x == -1) io.println("NO");
        else {
            io.println("YES");
            StringBuilder sb = new StringBuilder();
            while (end.x != start.x || end.y != start.y) {
                int di = dir[end.x][end.y];
                sb.append(c[dir[end.x][end.y]]);
                end.x += dx[di ^ 2]; end.y += dy[di ^ 2];
            }
            sb.reverse();
            io.println(sb.length());
            io.println(sb);
        }
        io.close();
    }
}

class State {
    int x, y, d;
    public State(int x, int y, int d) {
        this.x = x; this.y = y; this.d = d;
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
