V<V<Mint>> operator*(const V<V<Mint>>& a, const V<V<Mint>>& b) {
    // assume a = n * p, b = p * m
    int n = sz(a), p = sz(a[0]), m = sz(b[0]);
    V<V<Mint>> res(n, V<Mint>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

V<V<Mint>>& operator*=(V<V<Mint>>& a, const V<V<Mint>>& b) { return a = a * b; }

V<V<Mint>> pow(V<V<Mint>> a, ll b) {
    // only for square matrices
    int n = sz(a);
    V<V<Mint>> res(n, V<Mint>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a; b >>= 1;
    }
    return res;
}
