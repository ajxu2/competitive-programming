import java.util.*;
import java.io.*;

public class MajorityOpinion {
    static FastIO io = new FastIO();
    static void solve() throws IOException {
        int n = io.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = io.nextInt();
        if (n == 2) {
            if (a[0] == a[1]) io.println(a[0]);
            else io.println(-1);
            return;
        }
        Set<Integer> ans = new TreeSet<>();
        for (int i = 0; i < n-2; i++) {
            Map<Integer, Integer> m = new HashMap<>();
            for (int j = 0; j < 3; j++) {
                if (!m.containsKey(a[i+j])) m.put(a[i+j], 0);
                m.put(a[i+j], m.get(a[i+j])+1);
            }
            for (int j : m.keySet()) if (m.get(j) >= 2) ans.add(j);
        }
        if (ans.isEmpty()) io.println(-1);
        else {
            Object[] bruh = ans.toArray();
            for (int i = 0; i < bruh.length; i++) {
                io.print(bruh[i]);
                io.print(i == bruh.length-1 ? "\n" : " ");
            }
        }
    }
    static public void main(String[] args) throws IOException {
        int T = io.nextInt();
        while (T --> 0) solve();
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
}
