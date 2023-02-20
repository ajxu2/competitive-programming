#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

ll fexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return fexp(a, MOD-2); }

V<ll> fac(2000000, 1);
ll binom(ll n, ll k) { return fac[n] * inv(fac[k]) % MOD * inv(fac[n-k]) % MOD; }

int main() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    // precompute factorials
    for (int i = 1; i < 2000000; i++) fac[i] = fac[i-1] * i % MOD;
    ll ans = 1;
    for (int i = 0; i < n-1; i++) {
        if (a[i] >= a[i+1]) ans *= binom(a[i]/2, a[i+1]/2);
        else ans *= binom((a[i+1]-2)/2, (a[i]-2)/2);
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
