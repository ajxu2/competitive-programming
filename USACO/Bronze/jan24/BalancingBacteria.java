import java.util.*;
import java.io.*;

public class BalancingBacteria {
    static FastIO io = new FastIO();
    static public void main(String[] args) throws IOException {
        int n = io.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = io.nextLong();
        long sum = 0, add = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] += sum;
            ans += Math.abs(a[i]);
            add -= a[i];
            sum += add;
            sum -= a[i];
        }
        io.println(ans);
        io.close();
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
    public long nextLong() throws IOException { return Long.parseLong(next()); }
}
