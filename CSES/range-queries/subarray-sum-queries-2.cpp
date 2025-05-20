// created: 05-19-2025 Mon 11:05 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = (ll)1e18;

struct State {
    ll sum, max_pref, max_suf, max_sub;
};

struct Segtree {
    int n;
    V<State> tree;
    const State id = {0, 0, 0, 0};
    State cmb(State a, State b) {
        return {a.sum + b.sum,
            max(a.max_pref, a.sum + b.max_pref),
            max(b.max_suf, b.sum + a.max_suf),
            max(max(a.max_sub, b.max_sub), a.max_suf + b.max_pref)};
    }
    Segtree(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, id);
    }
    void upd(int i, State x) {
        tree[i += n] = x;
        i /= 2;
        while (i >= 1) {
            tree[i] = cmb(tree[2*i], tree[2*i+1]);
            i /= 2;
        }
    }
    State qry(int l, int r) {
        l += n, r += n;
        State resl = id, resr = id;
        while (l <= r) {
            if (l % 2 == 1)
                resl = cmb(resl, tree[l++]);
            if (r % 2 == 0)
                resr = cmb(tree[r--], resr);
            l /= 2, r /= 2;
        }
        return cmb(resl, resr);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    Segtree st(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int xp = max(0, x);
        st.upd(i, {x, xp, xp, xp});
    }
    while (q--) {
        int a, b; cin >> a >> b; a--, b--;
        cout << st.qry(a, b).max_sub << '\n';
    }
    return 0;
}
