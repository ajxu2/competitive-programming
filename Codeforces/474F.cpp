// created: 07-06-2024 Sat 02:12 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct State {
    int g, mnval, mnf;
    State(int g, int mnval, int mnf) : g(g), mnval(mnval), mnf(mnf) {}
    State(int v) : g(v), mnval(v), mnf(1) {}
    const static State id;
    State cmb(State o) {
        int ng = gcd(g, o.g);
        if (mnval < o.mnval) return State(ng, mnval, mnf);
        else if (mnval > o.mnval) return State(ng, o.mnval, o.mnf);
        else return State(ng, mnval, mnf + o.mnf);
    }
};
const State State::id = State(0, numeric_limits<int>::max(), 1);

struct Segtree {
    int n = 1;
    V<State> tree;
    Segtree(int _n) {
        while (n < _n) n <<= 1;
        tree.assign(n << 1, State::id);
    }
    void pull(int i) {
        tree[i] = tree[i << 1].cmb(tree[i << 1 ^ 1]);
    }
    void upd(int i, State v) {
        i += n; tree[i] = v; i >>= 1;
        while (i > 0) {
            pull(i); i >>= 1;
        }
    }
    State qry(int l, int r) {
        State res = State::id;
        l += n; r += n;
        while (l <= r) {
            if ((l & 1) == 1) res = res.cmb(tree[l++]);
            if ((r & 1) == 0) res = res.cmb(tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    Segtree segt(n);
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        segt.upd(i, State(s));
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        State res = segt.qry(l, r);
        if (res.mnval != res.g) cout << r - l + 1 << '\n';
        else cout << r - l + 1 - res.mnf << '\n';
    }
    return 0;
}
