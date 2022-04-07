// created: 04-07-2022 Thu 12:13 AM

import java.util.*;
import java.io.*;

public class CountingRooms {
    static final int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();
        int n = io.nextInt(), m = io.nextInt();
        boolean a[][] = new boolean[n+2][m+2];
        for (int i = 0; i < n; i++) {
            String s = io.next();
            for (int j = 0; j < m; j++) if (s.charAt(j) == '.') a[i+1][j+1] = true;
        }
        boolean vis[][] = new boolean[n+2][m+2];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!a[i][j] || vis[i][j]) continue;
                ans++;
                Queue<Pt> q = new LinkedList<>();
                q.add(new Pt(i, j)); vis[i][j] = true;
                while (!q.isEmpty()) {
                    Pt process = q.remove();
                    for (int k = 0; k < 4; k++) {
                        int nextX = process.x+dx[k], nextY = process.y+dy[k];
                        if (a[nextX][nextY] && !vis[nextX][nextY]) {
                            q.add(new Pt(nextX, nextY));
                            vis[nextX][nextY] = true;
                        }
                    }
                }
            }
        }
        io.println(ans);        
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
