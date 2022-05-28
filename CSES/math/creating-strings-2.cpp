// created: 05-28-2022 Sat 09:58 AM

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
    vector<ll> fac(1000001);
    fac[0] = 1;
    for (int i = 1; i <= 1000001; i++) fac[i] = fac[i-1] * i % MOD;
    string s; cin >> s;
    vector<int> freq(26, 0);
    for (char i : s) freq[i-'a']++;
    ll ans = fac[s.length()];
    for (int i : freq) {
        ans *= inv(fac[i]);
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
