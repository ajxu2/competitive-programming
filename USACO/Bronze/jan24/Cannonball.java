import java.util.*;
import java.io.*;

public class Cannonball {
    static FastIO io = new FastIO();
    static public void main(String[] args) throws IOException {
        int n = io.nextInt(), s = io.nextInt();
        boolean[] target = new boolean[n];
        int[] v = new int[n];
        boolean[] broken = new boolean[n];
        int ans = 0, cur = s - 1, pow = 1;
        for (int i = 0; i < n; i++) {
            target[i] = io.nextInt() == 1;
            v[i] = io.nextInt();
        }
        Set<Pair> vis = new TreeSet<>();
        for (;;) {
            // check current
            if (cur >= n || cur < 0) break;
            if (vis.contains(new Pair(cur, pow))) break;
            vis.add(new Pair(cur, pow));
            if (target[cur]) {
                if (Math.abs(pow) >= v[cur]) broken[cur] = true;
            } else {
                if (pow < 0) pow = -pow + v[cur];
                else pow = -pow - v[cur];
            }
            cur += pow;
        }
        for (int i = 0; i < n; i++) {
            if (broken[i]) ans++;
        }
        io.println(ans);
        io.close();
    }
}

class Pair implements Comparable<Pair> {
    int f, s;
    public Pair(int f, int s) {
        this.f = f;
        this.s = s;
    }
    public int compareTo(Pair o) {
        if (f == o.f) return Integer.compare(s, o.s);
        return Integer.compare(f, o.f);
    }
}

class FastIO extends PrintWriter {
    private String[] st = new String[0];
    private int stptr = 0;
    private BufferedReader br;
    public FastIO() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    public String next() throws IOException {
        while (stptr == st.length) {
            st = br.readLine().split("\\s+");
            stptr = 0;
        }
        return st[stptr++];
    }
    public int nextInt() throws IOException { return Integer.parseInt(next()); }
}
