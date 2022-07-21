// created: 07-21-2022 Thu 12:41 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Segtree {
    vector<ll> tree;
    int n;
    // the operator used in the segtree (must be associative and commutative)
    ll cmb(ll a, ll b) { return max(a, b); }
    // the identity of the operator: cmb(id, x) = cmb(x, id) = x
    const ll id = LLONG_MIN;
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    Segtree s(m+1);
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        s.upd(i, x);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int xs, ys, xf, yf, k; cin >> xs >> ys >> xf >> yf >> k;
        if (ys > yf) {
            swap(xs, xf); swap(ys, yf);
        }
        if ((xf - xs) % k != 0 || (yf - ys) % k != 0) {
            cout << "NO\n";
            continue;
        }
        int travrow = (n - xs) / k * k + xs;
        if (s.qry(ys, yf) >= travrow) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
