import java.util.*;
import java.io.*;

public class MergingCells {
    static FastIO io = new FastIO();
    static final int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        int[] ps = new int[n]; ps[0] = a[0];
        for (int i = 1; i < n; i++) ps[i] = ps[i-1] + a[i];
        long[] invs = new long[n+69];
        for (int i = 1; i < n+69; i++) invs[i] = inv(i);
        long[][] dp = new long[n][n]; // dp[i][j] = prob that i..j merges together AND propagates to full range
        dp[0][n-1] = 1;
        long[][] psdp1 = new long[n][n], psdp2 = new long[n][n]; // psdp1[i][j] = sum of dp[0..i][j] * inv, psdp2[i][j] = sum of dp[i][j..n-1] * inv
        for (int i = 0; i < n; i++) {
            int lptr = 0, rptr = n - 1;
            for (int j = n - 1; j >= i; j--) {
                int sum = i == 0 ? ps[j] : ps[j] - ps[i-1];
                while (lptr < i && (lptr == 0 ? ps[i-1] : ps[i-1] - ps[lptr-1]) > sum) lptr++;
                long add = i == 0 ? 0 : (lptr == 0 ? psdp1[i-1][j] : psdp1[i-1][j] - psdp1[lptr-1][j]);
                dp[i][j] += add;
                while (rptr > j && ps[rptr] - ps[j] >= sum) rptr--;
                add = j == n - 1 ? 0 : (rptr == n - 1 ? psdp2[i][j+1] : psdp2[i][j+1] - psdp2[i][rptr+1]);
                dp[i][j] += add;
                dp[i][j] %= MOD;
                if (dp[i][j] < 0) dp[i][j] += MOD;
                long val = dp[i][j] * invs[j - i] % MOD;
                if (i == 0) psdp1[i][j] = val;
                else psdp1[i][j] = (psdp1[i-1][j] + val) % MOD;
                if (j == n - 1) psdp2[i][j] = val;
                else psdp2[i][j] = (psdp2[i][j+1] + val) % MOD;
            }
        }
        for (int i = 0; i < n; i++) io.println(dp[i][i]);
        io.close();
    }
    static long pow(long a, int b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    static long inv(long a) { return pow(a, MOD - 2); }
}

class FastIO extends PrintWriter {
    private BufferedReader br;
    private String[] st = new String[0];
    private int stptr = 0;
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
