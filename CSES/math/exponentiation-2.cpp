// created: 05-23-2022 Mon 02:45 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fexp(ll a, ll b, int MOD) {
    ll ans = 1;
    while (b != 0) {
        if (b % 2 == 0) {
            b /= 2;
            a *= a;
            a %= MOD;
        } else {
            ans *= a;
            ans %= MOD;
            b--;
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    while (n--) {
        ll a, b, c; cin >> a >> b >> c;
        cout << fexp(a, fexp(b, c, 1000000006), 1000000007) << "\n";
    }
    return 0;
}
