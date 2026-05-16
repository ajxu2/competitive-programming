// created: 05-16-2026 Sat 08:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

ll fexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return fexp(a, MOD - 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    int mx = x1 + x2 + x3 + 5;
    V<ll> fact(mx);
    fact[0] = 1;
    for (int i = 1; i < mx; i++)
        fact[i] = fact[i - 1] * i % MOD;
    V<ll> ifact(mx);
    ifact[mx - 1] = inv(fact[mx - 1]);
    for (int i = mx - 2; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    auto binom = [&](int n, int k) -> ll {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    };
    auto stars_and_bars = [&](int n, int k) -> ll {
        return binom(n + k - 1, k - 1);
    };
    ll ans = 0;
    for (int i = 2; i < mx; i++) {
        // floor(i / 2) 1 chunks, ceil(i / 2) 3 chunks
        int chunks1 = i / 2, chunks3 = (i + 1) / 2;
        int spare1 = x1 - chunks1, spare2 = x2 - (i - 1), spare3 = x3 - chunks3;
        if (spare1 >= 0 && spare2 >= 0 && spare3 >= 0) {
            ll add = stars_and_bars(spare1, chunks1) * stars_and_bars(spare2, x1 + x3 + 1) % MOD * stars_and_bars(spare3, chunks3) % MOD;
            (ans += add) %= MOD;
        }
        // ceil(i / 2) 1 chunks, floor(i / 2) 3 chunks
        swap(chunks1, chunks3);
        spare1 = x1 - chunks1, spare3 = x3 - chunks3;
        if (spare1 >= 0 && spare2 >= 0 && spare3 >= 0) {
            ll add = stars_and_bars(spare1, chunks1) * stars_and_bars(spare2, x1 + x3 + 1) % MOD * stars_and_bars(spare3, chunks3) % MOD;
            (ans += add) %= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}
