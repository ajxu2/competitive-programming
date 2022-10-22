// created: 10-21-2022 Fri 05:35 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Segtree {
    int n;
    vector<ll> a;
    ll cmb(ll x, ll y) { return max(x, y); }
    const ll id = LLONG_MIN;
    Segtree(int _n) {
        n = _n;
        a = vector<ll>(2*n, id);
    }
    void upd(int i, ll x) {
        i += n; a[i] = x;
        i >>= 1;
        while (i > 0) {
            a[i] = cmb(a[2*i], a[2*i+1]);
            i >>= 1;
        }
    }
    ll qry(int i, int j) {
        i += n; j += n;
        ll ans = id;
        while (i <= j) {
            if ((i&1) == 1) ans = cmb(ans, a[i++]);
            if ((j&1) == 0) ans = cmb(ans, a[j--]);
            i >>= 1; j >>= 1;
        }
        return ans;
    }
};

int main() {
    // there exists an O(n log n) solution, but rn i'm fine with O(n log^2 n).
    int n, m; cin >> n >> m;
    Segtree s(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.upd(i, x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        // binary search on the first j s.t. max(rooms to j) >= desired
        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            ll res = s.qry(0, mid);
            if (res < x) l = mid+1;
            else r = mid;
        }
        if (l == n) cout << 0;
        else {
            cout << l+1;
            s.upd(l, s.qry(l, l)-x);
        }
        cout << " \n"[i == m-1];
    }
    return 0;
}
