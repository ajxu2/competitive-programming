// created: 04-16-2026 Thu 12:54 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

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

ll inv(ll a) {
    return fexp(a, MOD - 2);
}

void mod_sub(ll& a, ll b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

const int MX = 200'005;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    array<ll, MX> fac, ifac;
    fac[0] = 1;
    for (int i = 1; i < MX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    ifac[MX - 1] = inv(fac[MX - 1]);
    for (int i = MX - 2; i >= 0; i--)
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    auto paths = [&](int dx, int dy) {
        return fac[dx + dy] * ifac[dx] % MOD * ifac[dy] % MOD;
    };
    int h, w, n; cin >> h >> w >> n;
    V<array<int, 2>> a(n);
    for (auto& [r, c] : a)
        cin >> r >> c;
    a.push_back({h, w});
    sort(begin(a), end(a));
    V<ll> dp(n + 1);
    // dp[i] = number of paths from start to i that don't touch a wall
    for (int i = 0; i <= n; i++) {
        auto [r, c] = a[i];
        dp[i] = paths(r - 1, c - 1);
        for (int j = 0; j < i; j++) {
            auto [r1, c1] = a[j];
            if (r1 <= r && c1 <= c)
                mod_sub(dp[i], dp[j] * paths(r - r1, c - c1) % MOD);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
