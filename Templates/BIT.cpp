struct BIT {
    vector<ll> tree;
    int n;
    // construct BIT with n pieces of data
    BIT(int _n) {
        n = _n;
        tree = vector<ll>(n+1, 0);
    }
    // increase value at position i by v (1-indexed)
    void add(int i, ll v) {
        while (i <= n) {
            tree[i] += v;
            i += i & -i;
        }
    }
    // update value at position i to v (1-indexed)
    void upd(int i, ll v) {
        ll d = v - qry(i, i);
        add(i, d);
    }
    // query the sum from [1, a] (1-indexed)
    ll qry(int a) {
        ll res = 0;
        while (a > 0) {
            res += tree[a];
            a -= a & -a;
        }
        return res;
    }
    // query the sum from [a, b] (a and b are 1-indexed)
    ll qry(int a, int b) {
        return qry(b) - qry(a-1);
    }
};
