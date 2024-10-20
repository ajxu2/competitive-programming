// created: 10-18-2024 Fri 12:49 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;
struct State {
    ll sub, pre, suf, sum;
    const static State id;
};
const State State::id = {-INF, -INF, -INF, 0};

struct Segtree {
    int n;
    V<State> tree;
    State cmb(State s1, State s2) {
        return {
            max(max(s1.sub, s2.sub), s1.suf + s2.pre),
            max(s1.pre, s1.sum + s2.pre),
            max(s2.suf, s2.sum + s1.suf),
            s1.sum + s2.sum
        };
    }
    Segtree(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        tree.assign(2 * n, State::id);
    }
    void upd(int i, int x) {
        i += n;
        tree[i] = {x, x, x, x};
        for (i >>= 1; i > 0; i >>= 1) tree[i] = cmb(tree[2*i], tree[2*i+1]);
    }
    ll qry(int l, int r) {
        l += n; r += n;
        State sl = State::id, sr = State::id;
        while (l <= r) {
            if (l % 2 == 1) sl = cmb(sl, tree[l++]);
            if (r % 2 == 0) sr = cmb(tree[r--], sr);
            l >>= 1; r >>= 1;
        }
        return cmb(sl, sr).sub;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<array<int, 3>> operations(m);
    V<V<int>> st(n+1), en(n+1);
    for (array<int, 3>& i : operations) {
        cin >> i[0] >> i[1] >> i[2];
        i[0]--; i[1]--;
    }
    for (int i = 0; i < m; i++) {
        st[operations[i][0]].push_back(i);
        en[operations[i][1] + 1].push_back(i);
    }
    int q; cin >> q;
    V<array<int, 3>> queries(q);
    for (array<int, 3>& i : queries) {
        cin >> i[0] >> i[1] >> i[2];
        i[0]--; i[1]--; i[2]--;
    }
    V<V<int>> qs_to_answer(n);
    for (int i = 0; i < q; i++) {
        qs_to_answer[queries[i][0]].push_back(i);
    }
    Segtree seg(m);
    for (int i = 0; i < m; i++) seg.upd(i, 0);
    V<ll> ans(q);
    for (int i = 0; i < n; i++) {
        for (int j : st[i]) seg.upd(j, operations[j][2]);
        for (int j : en[i]) seg.upd(j, 0);
        for (int j : qs_to_answer[i]) ans[j] = seg.qry(queries[j][1], queries[j][2]);
    }
    for (ll i : ans) cout << i << '\n';
    return 0;
}
