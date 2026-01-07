// created: 11-15-2025 Sat 04:32 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

ll fexp(ll a, int b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1)
            (ans *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a) { return fexp(a, MOD - 2); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<ll> fac(k + 1), ifac(k + 1);
    fac[0] = 1;
    for (int i = 1; i <= k; i++)
        fac[i] = fac[i-1] * i % MOD;
    ifac[k] = inv(fac[k]);
    for (int i = k - 1; i >= 0; i--)
        ifac[i] = ifac[i+1] * (i+1) % MOD;
    auto choose = [&](int a, int b) {
        return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
    };
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        int mult = i % 2 == 0 ? 1 : -1;
        (ans += choose(k, i) * fexp(k - i, n) * mult) %= MOD;
    }
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';
    return 0;
}
