// created: 01-27-2024 Sat 11:51 AM

import java.util.*;
import java.io.*;

public class SalaryQueries {
    static FastIO io = new FastIO();
    static Random r = new Random();
    public static void main(String[] args) throws IOException {
        int n = io.nextInt(), q = io.nextInt();
        int[] a = new int[n];
        List<Integer> ptsl = new ArrayList<>(); // coordinate compression
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
            ptsl.add(a[i]);
        }
        Query[] qq = new Query[q];
        for (int i = 0; i < q; i++) qq[i] = new Query();
        for (int i = 0; i < q; i++) {
            qq[i].c = io.next().charAt(0);
            qq[i].f = io.nextInt(); qq[i].s = io.nextInt();
            if (qq[i].c == '!') {
                qq[i].f--;
                ptsl.add(qq[i].s);
            }
        }
        int[] pts = ptsl.stream().mapToInt(i -> i).toArray();
        ruffleSort(pts);
        BIT b = new BIT(pts.length+1);
        for (int i = 0; i < n; i++) b.add(Arrays.binarySearch(pts, a[i]), 1);
        for (Query i : qq) {
            if (i.c == '!') {
                b.add(Arrays.binarySearch(pts, a[i.f]), -1);
                b.add(Arrays.binarySearch(pts, i.s), 1);
                a[i.f] = i.s;
            } else {
                int l = Arrays.binarySearch(pts, i.f);
                if (l < 0) l = -l - 1;
                int r = Arrays.binarySearch(pts, i.s);
                if (r < 0) r = -r - 2;
                io.println(b.qry(l, r));
            }
        }
        io.close();
    }
    static void ruffleSort(int[] a) {
        // SecondThread would be proud
        for (int i = a.length - 1; i >= 0; i--) {
            int swp = r.nextInt(i + 1);
            int tmp = a[i]; a[i] = a[swp]; a[swp] = tmp;
        }
        Arrays.sort(a);
    }
}

class BIT {
    public int n;
    public long[] a, tree;
    public BIT(int n) {
        this.n = n;
        a = new long[n];
        tree = new long[n];
    }
    public void add(int i, long v) {
        a[i] += v;
        for (; i < n; i |= i + 1) tree[i] += v;
    }
    public void upd(int i, long v) { add(i, v - a[i]); }
    public long qry(int i) {
        long res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    public long qry(int i, int j) { return qry(j) - qry(i-1); }
    public int lower_bound(long v) {
        // returns first x st qry(x) >= v
        // or n if no such elements exist
        int res = -1; long sofar = 0;
        for (int i = 30; i >= 0; i--) {
            if (res + (1 << i) >= n) continue;
            if (sofar + tree[res+(1<<i)] < v) {
                res += 1 << i;
                sofar += tree[res];
            }
        }
        return res + 1;
    }
}

class Query {
    char c; int f, s;
    public Query() {}
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
