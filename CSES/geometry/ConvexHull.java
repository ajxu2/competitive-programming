// created: 04-03-2024 Wed 06:28 PM

import java.util.*;
import java.io.*;

public class ConvexHull {
    static FastIO io = new FastIO();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt();
        Vec[] a = new Vec[n];
        for (int i = 0; i < n; i++) a[i] = new Vec(io.nextInt(), io.nextInt());
        Arrays.sort(a, new Comparator<Vec>() {
            public int compare(Vec q, Vec w) {
                if (q.x == w.x) return Long.compare(q.y, w.y);
                return Long.compare(q.x, w.x);
            }
        });
        boolean[] hull = new boolean[n];
        LinkedList<Integer> stack = new LinkedList<>();
        // upper hull
        for (int i = 0; i < n; i++) {
            while (stack.size() >= 2 && a[stack.get(0)].cross(a[stack.get(1)], a[i]) < 0) stack.removeFirst();
            stack.addFirst(i);
        }
        for (int i : stack) hull[i] = true;
        // lower hull
        for (int i = 0; i < n; i++) {
            while (stack.size() >= 2 && a[stack.get(0)].cross(a[stack.get(1)], a[i]) > 0) stack.removeFirst();
            stack.addFirst(i);
        }
        for (int i : stack) hull[i] = true;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) if (hull[i]) ans.add(i);
        StringBuilder out = new StringBuilder();
        out.append(ans.size()).append('\n');
        for (int i : ans) out.append(a[i].x).append(' ').append(a[i].y).append('\n');
        io.print(out);
        io.close();
    }
}

class Vec {
    public long x, y;
    public Vec(long x, long y) {
        this.x = x; this.y = y;
    }
    public Vec sub(Vec o) { return new Vec(x - o.x, y - o.y); }
    public long cross(Vec o) { return x * o.y - y * o.x; }
    public long cross(Vec o1, Vec o2) { return o1.sub(this).cross(o2.sub(this)); }
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
