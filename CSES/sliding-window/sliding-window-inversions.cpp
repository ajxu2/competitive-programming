// created: 06-29-2025 Sun 11:43 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct BIT {
    int n;
    V<ll> tree;
    BIT(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void add(int i, ll v) {
        for (; i < n; i |= i + 1)
            tree[i] += v;
    }
    ll qry(int i) {
        ll sum = 0;
        for (; i >= 0; i &= i + 1, i--)
            sum += tree[i];
        return sum;
    }
    ll qry(int l, int r) { return qry(r) - qry(l-1); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    // compress
    V<int> b = a;
    sort(begin(b), end(b));
    for (int& i : a)
        i = lower_bound(begin(b), end(b), i) - begin(b);
    BIT bit(n);
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        bit.add(a[i], 1);
        ans += bit.qry(a[i] + 1, n - 1);
    }
    cout << ans << ' ';
    for (int i = k; i < n; i++) {
        bit.add(a[i], 1);
        ans += bit.qry(a[i] + 1, n - 1);
        bit.add(a[i-k], -1);
        ans -= bit.qry(a[i-k] - 1);
        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}
