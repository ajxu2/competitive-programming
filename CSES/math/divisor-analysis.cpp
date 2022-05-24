// created: 05-23-2022 Mon 02:53 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1000000007;

ll fexp(ll a, ll b) {
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

ll inv(ll a) {
    return fexp(a, MOD-2);
}

int main() {
    int n; cin >> n;
    ll num = 1, sum = 1, prod = 1, num2 = 1;
    for (int i = 0; i < n; i++) {
        int x, k; cin >> x >> k;
        ll tmp = (ll)k*(k+1)/2; tmp %= MOD-1;
        tmp *= num2; tmp %= MOD-1;
        prod = fexp(prod, k+1)*fexp(x, tmp); prod %= MOD;
        num *= k+1; num %= MOD;
        num2 *= k+1; num2 %= MOD-1;
        sum *= (fexp(x, k+1)-1); sum %= MOD;
        sum *= inv(x-1); sum %= MOD;
    }
    cout << num << " " << sum << " " << prod << "\n";
    return 0;
}
