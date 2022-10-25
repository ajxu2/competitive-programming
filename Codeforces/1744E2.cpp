// created: 10-22-2022 Sat 11:52 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> fac(ll a) {
    vector<ll> ret;
    for (ll i = 1; i*i <= a; i++) {
        if (a % i == 0) {
            ret.push_back(i);
            if (i*i != a) ret.push_back(a/i);
        }
    }
    return ret;
}

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    bool found = false;
    vector<ll> afac = fac(a), bfac = fac(b);
    vector<ll> totfac;
    for (ll i : afac) for (ll j : bfac) totfac.push_back(i*j);
    for (ll g : totfac) {
        int x = c/g*g;
        if (x <= a) continue;
        ll mod = a*b/g;
        int y = d/mod*mod;
        if (y > b) {
            cout << x << " " << y << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "-1 -1\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
