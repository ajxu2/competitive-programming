import java.util.*;
import java.io.*;

public class j_1811A {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int T = nextInt();
        while (T --> 0) {
            int n = nextInt(), d = nextInt();
            String s = next();
            int change = s.length();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) - '0' < d) {
                    change = i;
                    break;
                }
            }
            pw.println(s.substring(0, change) + (char)(d + '0') + s.substring(change));
        }
        br.close(); pw.close();
    }
    public static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}
