// created: 01-22-2026 Thu 02:33 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

// fenwick tree on max??!!
struct Fenwick {
    int n;
    V<ll> tree;
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int i, ll x) {
        for (; i < n; i |= i + 1)
            tree[i] = max(tree[i], x);
    }
    ll qry(int i) {
        ll res = 0;
        for (; i >= 0; i &= i + 1, i--)
            res = max(res, tree[i]);
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> h(n), a(n);
    for (int& i : h)
        cin >> i, i--;
    for (int& i : a)
        cin >> i;
    V<ll> dp(n);
    Fenwick fenwick(n);
    dp[0] = a[0];
    fenwick.upd(h[0], a[0]);
    for (int i = 1; i < n; i++) {
        dp[i] = fenwick.qry(h[i]) + a[i];
        fenwick.upd(h[i], dp[i]);
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}
