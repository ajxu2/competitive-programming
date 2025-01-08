// created: 01-08-2025 Wed 02:02 PM

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
        for (; i < n; i |= i + 1) tree[i] += v;
    }
    ll qry(int i) {
        ll res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    ll qry(int l, int r) { return qry(r) - qry(l-1); }
};

ll c2(int x) { return (ll)x * (x - 1) / 2; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> a(n);
    for (int& i : a) { cin >> i; i--; }
    // distinct values queries + overcounting yippee
    BIT bit(n);
    ll ans = 0;
    V<int> lst(m, -1);
    for (int i = 0; i < n; i++) {
        ans += 2 * bit.qry(lst[a[i]] + 1, i - 1);
        if (lst[a[i]] != -1) bit.add(lst[a[i]], -1);
        bit.add(i, 1);
        lst[a[i]] = i;
    }
    for (int i = 0; i < m; i++) ans += bit.qry(lst[i] + 1, n - 1);
    ans += c2(m);
    ans -= c2(m - bit.qry(0, n - 1));
    ans /= 2;
    cout << ans << '\n';
    return 0;
}
