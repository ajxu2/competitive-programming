int bitlen(int x) {
    int res;
    for (res = 0; x > 0; res++) x >>= 1;
    return res;
}

struct SparseTable {
    vector<vector<ll>> table; // table[i][j] = cmb(a[i], a[i+1], ... a[i+1<<j])
    int n;
    // the operator used in the sparse table (must be associative and satisfy cmb(x, x) = x)
    ll cmb(ll a, ll b) { return min(a, b); }
    // construct sparse table from vector
    SparseTable(vector<ll> a) {
        n = a.size();
        table = vector<vector<ll>>(n, vector<ll>(bitlen(n)));
        for (int i = 0; i < n; i++) table[i][0] = a[i];
        for (int i = 1; i < bitlen(n); i++) {
            for (int j = 0; j < n; j++) {
                if (j+(1<<(i-1)) >= n) table[j][i] = table[j][i-1];
                else table[j][i] = cmb(table[j][i-1], table[j+(1<<(i-1))][i-1]);
            }
        }
    }
    // query the range [a, b]
    ll qry(int a, int b) {
        int loglen = bitlen(b-a+1)-1;
        return cmb(table[a][loglen], table[b-(1<<loglen)+1][loglen]);
    }
};
