#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

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

void solve() {
    ll n, k, x; cin >> n >> k >> x;
    if (x < 0) {
        k = n - k; x = -x;
    }
    V<ll> a(n);
    for (ll& i : a) cin >> i;
    V<ll> p1(n+1, 0), p2(n+1, 0);
    Segtree s1(n+1), s2(n+1);
    s1.upd(0, 0); s2.upd(0, 0);
    for (int i = 1; i <= n; i++) {
        p1[i] = p1[i-1] + a[i-1] + x;
        s1.upd(i, p1[i]);
        p2[i] = p2[i-1] + a[i-1] - x;
        s2.upd(i, p2[i]);
    }
    ll ans = -1e18;
    for (int i = 1; i <= k; i++) {
        ans = max(ans, p1[i] - s1.qry(0, i));
    }
    for (int i = k+1; i <= n; i++) {
        ans = max(ans, p1[i] - s1.qry(i-k, i));
        ans = max(ans, p2[i] - s2.qry(0, i-k) + 2 * k * x);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
