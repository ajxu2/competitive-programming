class HashedString {
    static final int MOD = 2_000_000_011, p = new Random().nextInt(MOD - 100) + 100;
    static long[] pow = new long[]{1};
    int n; long[] hsh;
    public HashedString(String s) {
        n = s.length();
        hsh = new long[n];
        while (pow.length < n) {
            pow = Arrays.copyOf(pow, pow.length << 1);
            for (int i = pow.length >> 1; i < pow.length; i++) pow[i] = pow[i-1] * p % MOD;
        }
        if (n == 0) return;
        hsh[0] = s.charAt(0);
        for (int i = 1; i < n; i++) hsh[i] = (hsh[i-1] * p + s.charAt(i)) % MOD;
    }
    public int length() { return n; }
    public long substring(int l, int r) {
        if (l == 0) return hsh[r-1];
        long res = (hsh[r-1] - hsh[l-1] * pow[r-l]) % MOD;
        return res < 0 ? res + MOD : res;
    }
    public long substring(int l) { return substring(l, n); }
}
