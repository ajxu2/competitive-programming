// created: 04-25-2026 Sat 08:00 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;
const int HALF = (MOD + 1) >> 1;

struct LazySeg { // range sum, range sum square
    int n;
    V<int> l, r;
    V<array<ll, 2>> tree;
    V<ll> lzAdd;
    array<ll, 2> cmb(array<ll, 2> a, array<ll, 2> b) {
        return {(a[0] + b[0]) % MOD, (a[1] + b[1]) % MOD};
    }
    void pull(int v) {
        tree[v] = cmb(tree[2 * v], tree[2 * v + 1]);
    }
    void push(int v) {
        (tree[v][1] += 2 * lzAdd[v] * tree[v][0]) %= MOD;
        (tree[v][1] += lzAdd[v] * lzAdd[v] % MOD * (r[v] - l[v])) %= MOD;
        (tree[v][0] += (r[v] - l[v]) * lzAdd[v]) %= MOD;
        if (v < n) {
            (lzAdd[2 * v] += lzAdd[v]) %= MOD;
            (lzAdd[2 * v + 1] += lzAdd[v]) %= MOD;
        }
        lzAdd[v] = 0;
    }
    LazySeg(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        l.resize(2 * n);
        r.resize(2 * n);
        tree.resize(2 * n);
        lzAdd.assign(2 * n, 0);
        for (int i = 0; i < n; i++) {
            l[i + n] = i;
            r[i + n] = i + 1;
            tree[i + n] = {0, 0};
        }
        for (int i = n - 1; i >= 1; i--) {
            l[i] = l[2 * i];
            r[i] = r[2 * i + 1];
            pull(i);
        }
    }
    void range_add(int node, int ll, int rr, int v) {
        push(node);
        if (r[node] <= ll || rr <= l[node])
            return;
        if (ll <= l[node] && r[node] <= rr) {
            (lzAdd[node] += v) %= MOD;
            push(node);
            return;
        }
        range_add(2 * node, ll, rr, v);
        range_add(2 * node + 1, ll, rr, v);
        pull(node);
    }
    void range_add(int ll, int rr, int v) {
        range_add(1, ll, rr, v);
    }
    array<ll, 2> qry(int node, int ll, int rr) {
        push(node);
        if (r[node] <= ll || rr <= l[node])
            return {0, 0};
        if (ll <= l[node] && r[node] <= rr)
            return tree[node];
        return cmb(qry(2 * node, ll, rr), qry(2 * node + 1, ll, rr));
    }
    array<ll, 2> qry(int ll, int rr) {
        return qry(1, ll, rr);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    LazySeg lzseg(n);
    while (q--) {
        int l, r, v; cin >> l >> r >> v; l--;
        lzseg.range_add(l, r, v);
        auto [sum, sumsq] = lzseg.qry(l, r);
        ll ans = sum * (sum - 1) % MOD * HALF % MOD;
        ll thing = (sumsq - sum) * HALF % MOD;
        (ans -= thing) %= MOD;
        if (ans < 0)
            ans += MOD;
        cout << ans << '\n';
    }
    return 0;
}
