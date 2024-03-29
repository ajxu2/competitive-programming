// created: 03-29-2024 Fri 11:50 AM

import java.util.*;
import java.io.*;

public class FixedLengthPaths1 {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), k = io.nextInt();
        int[] head = new int[n], to = new int[2*n-2], nxt = new int[2*n-2];
        Arrays.fill(head, -1);
        for (int i = 0; i < n-1; i++) {
            int u = io.nextInt() - 1, v = io.nextInt() - 1;
            to[2*i] = v; nxt[2*i] = head[u]; head[u] = 2*i;
            to[2*i+1] = u; nxt[2*i+1] = head[v]; head[v] = 2*i+1;
        }
        // get bfs order
        int[] bfsOrder = new int[n], par = new int[n];
        int ptr = n-1;
        Queue<Integer> bfs = new ArrayDeque<>();
        par[0] = -1; bfs.offer(0);
        while (!bfs.isEmpty()) {
            int cur = bfs.poll();
            bfsOrder[ptr--] = cur;
            for (int whar = head[cur]; whar != -1; whar = nxt[whar]) {
                int i = to[whar];
                if (i == par[cur]) continue;
                par[i] = cur; bfs.offer(i);
            }
        }
        // magic small to large stuff
        List<Integer>[] freq = new List[n];
        long ans = 0;
        for (int i : bfsOrder) {
            List<Integer> sofar = new ArrayList<>();
            for (int whar = head[i]; whar != -1; whar = nxt[whar]) {
                int j = to[whar];
                if (j == par[i]) continue;
                // swap
                if (freq[j].size() > sofar.size()) {
                    List<Integer> tmp = sofar; sofar = freq[j]; freq[j] = tmp;
                }
                // add
                for (int l = 0; l < freq[j].size(); l++) {
                    int thisDepth = freq[j].size() - 1 - l;
                    int otherDepth = k - 2 - thisDepth;
                    if (otherDepth < 0 || otherDepth >= sofar.size()) continue;
                    ans += (long)freq[j].get(l) * sofar.get(sofar.size() - 1 - otherDepth);
                }
                // merge
                for (int l = 0; l < freq[j].size(); l++) {
                    int thisDepth = freq[j].size() - 1 - l;
                    int otherIdx = sofar.size() - 1 - thisDepth;
                    sofar.set(otherIdx, sofar.get(otherIdx) + freq[j].get(l));
                }
            }
            if (k - 1 >= 0 && k - 1 < sofar.size()) ans += sofar.get(sofar.size() - 1 - (k - 1));
            sofar.add(1); // increase all depths
            freq[i] = sofar;
        }
        io.println(ans);
        io.close();
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
