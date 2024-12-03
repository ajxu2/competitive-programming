// created: 12-02-2024 Mon 03:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct BIT {
    int n;
    V<ll> tree, a;
    BIT(int _n) {
        n = _n;
        tree.assign(n, 0);
        a.assign(n, 0);
    }
    void add(int i, ll v) {
        a[i] += v;
        for (; i < n; i |= i + 1) tree[i] += v;
    }
    void upd(int i, ll v) {
        add(i, v - a[i]);
    }
    ll qry(int i) {
        ll res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    ll qry(int l, int r) { return qry(r) - qry(l - 1); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    V<pair<int, ll>> iharbors(m);
    for (int i = 0; i < m; i++) {
        cin >> iharbors[i].first;
        iharbors[i].first--;
    }
    for (int i = 0; i < m; i++) cin >> iharbors[i].second;
    sort(begin(iharbors), end(iharbors));
    BIT bit(n);
    for (int i = 1; i < m; i++) {
        int diff = iharbors[i].first - iharbors[i-1].first;
        bit.upd(iharbors[i].first, iharbors[i-1].second * diff * (diff - 1) / 2);
    }
    set<pair<int, ll>> harbors(begin(iharbors), end(iharbors));
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            pair<int, ll> tmp; cin >> tmp.first >> tmp.second;
            tmp.first--;
            auto it = harbors.lower_bound(tmp);
            pair<int, ll> prv = *prev(it), nxt = *it;
            int diff = tmp.first - prv.first;
            bit.upd(tmp.first, prv.second * diff * (diff - 1) / 2);
            diff = nxt.first - tmp.first;
            bit.upd(nxt.first, tmp.second * diff * (diff - 1) / 2);
            harbors.insert(tmp);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            ll ans = bit.qry(l, r);
            if (l != 0) {
                auto it = harbors.lower_bound({l, 0});
                pair<int, ll> prv = *prev(it), nxt = *it;
                int diff = nxt.first - prv.first;
                ans -= prv.second * diff * (diff - 1) / 2;
                diff = nxt.first - l + 1;
                ans += prv.second * diff * (diff - 1) / 2;
            }
            if (r != n - 1) {
                auto it = harbors.lower_bound({r, 1e18});
                pair<int, ll> prv = *prev(it), nxt = *it;
                int diff = nxt.first - prv.first;
                ans += prv.second * diff * (diff - 1) / 2;
                diff = nxt.first - r;
                ans -= prv.second * diff * (diff - 1) / 2;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
