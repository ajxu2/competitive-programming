// created: 12-25-2025 Thu 02:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

struct LazySeg { // min, max
    int n;
    V<int> l, r;
    V<array<int, 2>> tree;
    V<int> lzAdd;
    array<int, 2> cmb(array<int, 2> a, array<int, 2> b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    void pull(int v) {
        tree[v] = cmb(tree[2 * v], tree[2 * v + 1]);
    }
    void push(int v) {
        tree[v][0] += lzAdd[v];
        tree[v][1] += lzAdd[v];
        if (v < n) {
            lzAdd[2 * v] += lzAdd[v];
            lzAdd[2 * v + 1] += lzAdd[v];
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
            lzAdd[node] += v;
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
    array<int, 2> qry(int node, int ll, int rr) {
        push(node);
        if (r[node] <= ll || rr <= l[node])
            return {INF, -INF};
        if (ll <= l[node] && r[node] <= rr)
            return tree[node];
        return cmb(qry(2 * node, ll, rr), qry(2 * node + 1, ll, rr));
    }
    array<int, 2> qry(int ll, int rr) {
        return qry(1, ll, rr);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    LazySeg lazy_seg(n); // stuff greater than x in pile 1 - pile 2
    for (int i = 0; i < n; i++) {
        int c, s; cin >> c >> s;
        lazy_seg.range_add(0, c, s == 1 ? 1 : -1);
        auto [mn, mx] = lazy_seg.qry(0, n);
        if (mn >= 0)
            cout << '>';
        else if (mx <= 0)
            cout << '<';
        else
            cout << '?';
        cout << '\n';
    }
    return 0;
}
