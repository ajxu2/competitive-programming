import java.util.*;
import java.io.*;

public class j_1820A {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int T = nextInt();
        while (T --> 0) {
            String s = next();
            if (s.equals("^")) {
                pw.println(1);
                continue;
            }
            String[] sp = s.split("\\^");
            int ans = 0;
            for (String i : sp) {
                if (!i.equals("") && i.charAt(0) == '_') ans += (i.length() - 1);
            }
            if (s.charAt(0) == '_') ans++;
            if (s.charAt(s.length()-1) == '_') ans++;
            pw.println(ans);
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
