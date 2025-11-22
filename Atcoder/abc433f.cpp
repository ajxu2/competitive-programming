// created: 11-22-2025 Sat 07:41 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

ll fexp(ll a, int b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return fexp(a, MOD - 2); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    V<ll> fact(n + 1), ifact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    auto choose = [&](int n, int k) {
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    };
    ll ans = 0;
    for (int i = 0; i < 9; i++) {
        V<int> pref(n), suff(n);
        pref[0] = (s[0] - '0' == i);
        for (int j = 1; j < n; j++) {
            pref[j] = pref[j - 1] + (s[j] - '0' == i);
        }
        suff[n - 1] = (s[n - 1] - '0' == i + 1);
        for (int j = n - 2; j >= 0; j--) {
            suff[j] = suff[j + 1] + (s[j] - '0' == i + 1);
        }
        for (int j = 0; j < n - 1; j++) {
            if (s[j] - '0' == i && suff[j + 1] >= 1)
                ans += choose(pref[j] + suff[j + 1] - 1, suff[j + 1] - 1);
        }
    }
    cout << ans % MOD << '\n';
    return 0;
}
