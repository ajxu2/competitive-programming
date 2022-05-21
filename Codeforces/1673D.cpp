// created: 05-21-2022 Sat 12:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// for some reason stupid mingw uses g++ 6.3 which doesn't have gcd support so i have to make it myself

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
    return x/gcd(x, y)*y;
}

void solve() {
    ll fst1, rat1, y, fst2, rat2, z;
    cin >> fst1 >> rat1 >> y >> fst2 >> rat2 >> z;
    ll lst1 = fst1+rat1*(y-1), lst2 = fst2+rat2*(z-1);
    ll ans = 0;
    if (rat2 % rat1 != 0 || fst2 < fst1 || lst2 > lst1 || (fst2-fst1) % rat1 != 0) ans = 0;
    else if (lst2 + rat2 > lst1 || fst2 - rat2 < fst1) ans = -1;
    else {
        // find factors of rat2
        vector<ll> fac;
        for (int i = 1; i*i <= rat2; i++) {
            if (rat2 % i == 0) {
                fac.push_back(i);
                if (i*i != rat2) fac.push_back(rat2/i);
            }
        }
        // brute force over all factors
        for (ll i : fac) {
            if (lcm(rat1, i) == rat2) {
                ans += (rat2/i)*(rat2/i);
                ans %= 1000000007;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
