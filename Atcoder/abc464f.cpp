// created: 06-27-2026 Sat 08:30 AM

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
    int n; ll x; cin >> n >> x;
    V<ll> a(n);
    for (ll& i : a)
        cin >> i;
    V<ll> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    ll tot = accumulate(begin(a), end(a), 0LL);
    ll ans = 0;
    // sum |S|! * (n - |S|)! / n! * (tot - sum S) / (n - |S|),
    // = |S|! * (n - |S| - 1)! / n! * (tot - sum S)
    // over all S with sum < x
    int meet_n = n / 2, middle_n = n - meet_n;
    V<pair<ll, int>> meet; // (sum, popcnt)
    V<V<ll>> middle(middle_n + 1); // middle[popcnt] = sums
    for (int mask = 0; mask < (1 << meet_n); mask++) {
        ll sum = 0;
        int popcnt = 0;
        for (int j = 0; j < meet_n; j++) {
            if ((mask >> j) & 1) {
                sum += a[j];
                popcnt++;
            }
        }
        meet.push_back({sum, popcnt});
    }
    for (int mask = 0; mask < (1 << middle_n); mask++) {
        ll sum = 0;
        int popcnt = 0;
        for (int j = 0; j < middle_n; j++) {
            if ((mask >> j) & 1) {
                sum += a[meet_n + j];
                popcnt++;
            }
        }
        middle[popcnt].push_back(sum);
    }
    sort(begin(meet), end(meet), greater<pair<ll, int>>());
    for (int i = 0; i <= middle_n; i++)
        sort(begin(middle[i]), end(middle[i]));
    V<ll> ptr(middle_n + 1, 0), ptr_sum(middle_n + 1, 0);
    for (auto [sum, popcnt] : meet) {
        for (int i = 0; i <= middle_n; i++) {
            while (ptr[i] < ssize(middle[i]) && middle[i][ptr[i]] < x - sum) {
                (ptr_sum[i] += middle[i][ptr[i]]) %= MOD;
                ptr[i]++;
            }
            int sz = popcnt + i;
            if (sz == n)
                continue;
            ll sum_tot_minus_sum = ((tot - sum) % MOD * ptr[i] % MOD - ptr_sum[i]) % MOD;
            if (sum_tot_minus_sum < 0)
                sum_tot_minus_sum += MOD;
            ans += fact[sz] * fact[n - 1 - sz] % MOD * sum_tot_minus_sum % MOD;
            ans %= MOD;
        }
    }
    (ans *= inv(fact[n])) %= MOD;
    cout << ans << '\n';
    return 0;
}
