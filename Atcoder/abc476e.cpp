// created: 09-19-2026 Sat 10:57 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

struct Segtree {
    using T = array<int, 4>; // (min, idx, max, idx)
    const T id = {INF, -1, -INF, -1};
    T cmb(const T& a, const T& b) {
        auto [min1, mini1, max1, maxi1] = a;
        auto [min2, mini2, max2, maxi2] = b;
        array<int, 4> c;
        if (min1 < min2) {
            c[0] = min1;
            c[1] = mini1;
        } else {
            c[0] = min2;
            c[1] = mini2;
        }
        if (max1 > max2) {
            c[2] = max1;
            c[3] = maxi1;
        } else {
            c[2] = max2;
            c[3] = maxi2;
        }
        return c;
    }
    int n;
    V<T> tree;
    Segtree(const V<int>& a) {
        int _n = ssize(a);
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, id);
        for (int i = 0; i < _n; i++)
            tree[i + n] = {a[i], i, a[i], i};
        for (int i = n - 1; i > 0; i--)
            tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
    }
    void upd(int i, int x) {
        tree[i + n] = {x, i, x, i};
        i += n;
        for (i >>= 1; i > 0; i >>= 1)
            tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
    }
    array<int, 4> qry(int l, int r) {
        array<int, 4> res = id;
        l += n, r += n;
        while (l <= r) {
            if ((l & 1) == 1)
                res = cmb(res, tree[l++]);
            if ((r & 1) == 0)
                res = cmb(res, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> p(n);
    for (int& i : p)
        cin >> i;
    Segtree segt(p);
    while (m--) {
        int l, r; cin >> l >> r; l--, r--;
        auto [min, min_idx, max, max_idx] = segt.qry(l, r);
        swap(p[min_idx], p[max_idx]);
        segt.upd(min_idx, max);
        segt.upd(max_idx, min);
    }
    for (int i = 0; i < n; i++)
        cout << p[i] << " \n"[i == n - 1];
    return 0;
}
