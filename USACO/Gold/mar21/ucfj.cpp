// created: 10-18-2022 Tue 11:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    int n;
    vector<ll> a;
    BIT(int _n) {
        n = _n;
        a = vector<ll>(n+1, 0);
    }
    void upd(int i, ll x) {
        while (i <= n) {
            a[i] += x; i += i & -i;
        }
    }
    ll qry(int i) {
        ll res = 0;
        while (i > 0) {
            res += a[i]; i -= i & -i;
        }
        return res;
    }
    ll qry(int i, int j) {
        return qry(j) - qry(i-1);
    }
};

int main() {
    int n; cin >> n;
    vector<int> lst(n+1, -1); // last occurrence of some breed
    BIT bit(n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        if (lst[b] == -1) {
            ans += bit.qry(1, i);
        } else {
            ans += bit.qry(lst[b]+1, i);
            bit.upd(lst[b], -1);
        }
        bit.upd(i, 1);
        lst[b] = i;
    }
    cout << ans << "\n";
    return 0;
}
