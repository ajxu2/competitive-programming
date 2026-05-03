// created: 05-02-2026 Sat 04:24 PM

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

ll inv(ll a) {
    return fexp(a, MOD - 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<int, 2>> a(n);
    for (auto& [l, r] : a)
        cin >> l >> r;
    V<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    V<ll> ifact(n + 1);
    ifact[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    auto binom = [&](int n, int k) {
        return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
    };
    // Fix the number of people on team A. Then every person has 4 cases:
    // must be A, must be B, can be either, or can be neither.
    // We can keep track of these quantities across all choices of team A sizes
    // and for each size, we just add a binomial coefficient to the answer.
    V<int> p(n + 1, 0);
    for (auto [l, r] : a) {
        p[l]++; p[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        p[i] += p[i - 1];
    V<V<int>> by_l(n);
    for (auto [l, r] : a)
        by_l[l].push_back(r);
    V<int> thing(n + 1, 0); // ???
    ll ans = 0;
    int cnt_ab = 0;
    for (int i = 1; i <= (n - 1) / 2; i++) {
        cnt_ab += thing[n - i];
        for (int j : by_l[i]) {
            thing[j]++;
            if (j >= n - i)
                cnt_ab++;
        }
        int cnt_a = p[i] - cnt_ab, cnt_b = p[n - i] - cnt_ab;
        if (cnt_a + cnt_b + cnt_ab == n && cnt_a <= i && cnt_b <= n - i)
            (ans += binom(cnt_ab, i - cnt_a)) %= MOD;
    }
    (ans *= 2) %= MOD;
    if (n % 2 == 0 && p[n / 2] == n)
        (ans += binom(n, n / 2)) %= MOD;
    cout << ans << '\n';
    return 0;
}
