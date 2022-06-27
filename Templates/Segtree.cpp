struct Segtree {
    vector<ll> tree;
    int n;
    // the operator used in the segtree (must be associative and commutative)
    ll cmb(ll a, ll b) { return min(a, b); }
    // the identity of the operator: cmb(id, x) = cmb(x, id) = x
    const ll id = LLONG_MAX;
    // construct segment tree with n pieces of data
    Segtree(int _n) {
        n = _n;
        tree = vector<ll>(2*n, id);
    }
    // update value at position i to v
    void upd(int i, ll v) {
        i += n; tree[i] = v;
        while (i > 1) {
            i /= 2; tree[i] = cmb(tree[2*i], tree[2*i+1]);
        }
    }
    // query the range [a, b]
    ll qry(int a, int b) {
        ll res = id;
        a += n; b += n;
        while (a <= b) {
            if (a % 2 == 1) res = cmb(res, tree[a++]);
            if (b % 2 == 0) res = cmb(res, tree[b--]);
            a /= 2; b /= 2;
        }
        return res;
    }
};
