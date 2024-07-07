// created: 07-07-2024 Sun 10:06 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct BIT {
    int n;
    V<ll> a, tree;
    BIT(int _n) {
        n = _n;
        a.assign(n, 0);
        tree.assign(n, 0);
    }
    void add(int i, ll v) {
        a[i] += v;
        while (i < n) {
            tree[i] += v;
            i |= i + 1;
        }
    }
    void upd(int i, ll v) {
        ll d = v - a[i];
        add(i, d);
    }
    ll qry(int i) {
        ll res = 0;
        while (i >= 0) {
            res += tree[i];
            i &= i + 1; i--;
        }
        return res;
    }
    ll qry(int i, int j) {
        return qry(j) - qry(i-1);
    }
};

void compress(V<int>& a) {
    V<int> b = a;
    sort(begin(b), end(b));
    for (int& i : a) i = lower_bound(begin(b), end(b), i) - begin(b);
}

void solve() {
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    V<int> c = a, d = b;
    sort(begin(c), end(c)); sort(begin(d), end(d));
    if (c != d) {
        cout << "NO\n";
        return;
    }
    compress(a); compress(b);
    BIT bita(n), bitb(n);
    ll inva = 0, invb = 0;
    for (int i = n-1; i >= 0; i--) {
        inva += bita.qry(a[i] - 1);
        bita.add(a[i], 1);
        invb += bitb.qry(b[i] - 1);
        bitb.add(b[i], 1);
    }
    if (inva % 2 == invb % 2) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
