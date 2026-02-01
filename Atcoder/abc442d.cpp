// created: 01-24-2026 Sat 07:13 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct Fenwick {
    int n;
    V<ll> a, tree;
    Fenwick(int _n) {
        n = _n;
        a.assign(n, 0);
        tree.assign(n, 0);
    }
    void add(int i, ll v) {
        a[i] += v;
        for (; i < n; i |= i + 1)
            tree[i] += v;
    }
    void upd(int i, ll v) {
        add(i, v - a[i]);
    }
    int qry(int i) {
        ll res = 0;
        for (; i >= 0; i &= i + 1, i--)
            res += tree[i];
        return res;
    }
    int qry(int i, int j) {
        return qry(j) - qry(i - 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    Fenwick fenwick(n);
    for (int i = 0; i < n; i++)
        fenwick.add(i, a[i]);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i; i--;
            fenwick.upd(i, a[i + 1]);
            fenwick.upd(i + 1, a[i]);
            swap(a[i], a[i + 1]);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << fenwick.qry(l, r) << '\n';
        }
    }
    return 0;
}
