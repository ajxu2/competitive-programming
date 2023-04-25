import java.util.*;
import java.io.*;

public class j_1814A {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        long T = longgggg();
        while (T --> 0) {
            long n = longgggg(), k = longgggg();
            if (n % 2 == 0) {
                pw.println("YES");
            } else if (k % 2 == 0) {
                pw.println("NO");
            } else if (n - k < 0) {
                pw.println("NO");
            } else pw.println("YES");
        }
        br.close(); pw.close();
    }
    public static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    public static long longgggg() throws IOException {
        return Long.parseLong(next());
    }
}
