struct BIT {
    int n;
    V<ll> a, tree;
    BIT(int _n) {
        n = _n;
        a.assign(n, 0);
        tree.assign(n, 0);
    }
    void add(int i, ll v) {
        a[i] += v;
        while (i < n) {
            tree[i] += v;
            i |= i + 1;
        }
    }
    void upd(int i, ll v) {
        ll d = v - a[i];
        add(i, d);
    }
    ll qry(int i) {
        ll res = 0;
        while (i >= 0) {
            res += tree[i];
            i &= i + 1; i--;
        }
        return res;
    }
    ll qry(int i, int j) {
        return qry(j) - qry(i-1);
    }
};
