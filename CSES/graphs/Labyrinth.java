// created: 04-07-2022 Thu 09:11 PM

import java.util.*;
import java.io.*;

public class Labyrinth {
    static final int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    static final char[] dc = {'D', 'R', 'U', 'L'};
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt(), m = io.nextInt();
        Pt start = new Pt(0, 0), end = new Pt(0, 0);
        boolean a[][] = new boolean[n+2][m+2], vis[][] = new boolean[n+2][m+2];
        int dir[][] = new int[n+2][m+2];
        for (int i = 0; i < n; i++) {
            String s = io.next();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '.' || s.charAt(j) == 'A' || s.charAt(j) == 'B') a[i+1][j+1] = true;
                if (s.charAt(j) == 'A') start = new Pt(i+1, j+1);
                if (s.charAt(j) == 'B') end = new Pt(i+1, j+1);
            }
        }
        Queue<Pt> q = new LinkedList<>();
        q.add(start); vis[start.x][start.y] = true;
        boolean found = false;
        while (!q.isEmpty()) {
            Pt process = q.remove();
            if (process.x == end.x && process.y == end.y) {
                found = true; break;
            } 
            for (int i = 0; i < 4; i++) {
                int newX = process.x+dx[i], newY = process.y+dy[i];
                if (a[newX][newY] && !vis[newX][newY]) {
                    q.add(new Pt(newX, newY));
                    vis[newX][newY] = true;
                    dir[newX][newY] = i;
                }
            }
        }
        if (!found) io.println("NO");
        else {
            io.println("YES");
            int ptrX = end.x, ptrY = end.y;
            StringBuilder sb = new StringBuilder();
            while (ptrX != start.x || ptrY != start.y) {
                sb.append(dc[dir[ptrX][ptrY]]);
                int reverseDir = (dir[ptrX][ptrY]+2)%4;
                ptrX += dx[reverseDir]; ptrY += dy[reverseDir];
            }
            sb.reverse();
            io.println(sb.length());
            io.println(sb);
        }
        io.close();
    }
    static class Pt {
        public int x, y;
        public Pt(int x, int y) {
            this.x = x; this.y = y;
        }
    }
    static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;
        // standard input
        public Kattio() { this(System.in,System.out); }
        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        // USACO-style file input
        public Kattio(String problemName) throws IOException {
            super(problemName+".out");
            r = new BufferedReader(new FileReader(problemName+".in"));
        }
        // returns null if no more input
        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) {}
            return null;
        }
        public int nextInt() { return Integer.parseInt(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public long nextLong() { return Long.parseLong(next()); }
    }
}
