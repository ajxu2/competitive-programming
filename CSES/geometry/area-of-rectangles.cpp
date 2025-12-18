// created: 12-17-2025 Wed 03:42 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct LazySeg { // cnt min
    int n;
    V<int> l, r;
    V<array<int, 2>> tree;
    V<int> lzAdd;
    array<int, 2> cmb(array<int, 2> a, array<int, 2> b) {
        if (a[0] < b[0])
            return a;
        if (a[0] > b[0])
            return b;
        return {a[0], a[1] + b[1]};
    }
    void pull(int v) {
        tree[v] = cmb(tree[2 * v], tree[2 * v + 1]);
    }
    void push(int v) {
        tree[v][0] += lzAdd[v];
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
            tree[i + n] = {0, 1};
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
    int qry() { // number of nonzero elts
        if (tree[1][0] != 0)
            return n;
        return n - tree[1][1];
    }
};

const int SHIFT = 1'000'000;

struct Query {
    int x, y1, y2;
    bool add; // whether this is +1 or -1
    bool operator<(const Query& o) { return x < o.x; }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<Query> qs(2 * n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        y1 += SHIFT; y2 += SHIFT;
        qs[2 * i] = {x1, y1, y2, true};
        qs[2 * i + 1] = {x2, y1, y2, false};
    }
    sort(begin(qs), end(qs));
    LazySeg lazyseg(2 * SHIFT);
    ll ans = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        auto [x, y1, y2, add] = qs[i];
        lazyseg.range_add(y1, y2, add ? 1 : -1);
        ans += (ll)(qs[i + 1].x - x) * lazyseg.qry();
    }
    cout << ans << '\n';
    return 0;
}
