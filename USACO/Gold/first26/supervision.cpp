#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

#if __cplusplus < 202100
#define ssize(a) ((int)a.size())
#endif

const int MOD = 1'000'000'007;
const int HALF = (MOD + 1) / 2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    V<int> coaches, campers;
    for (int i = 0; i < n; i++) {
        int p, o; cin >> p >> o;
        if (o == 1)
            coaches.push_back(p);
        else
            campers.push_back(p);
    }
    V<ll> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    V<ll> ipow2(n + 1);
    ipow2[0] = 1;
    for (int i = 1; i <= n; i++)
        ipow2[i] = ipow2[i - 1] * HALF % MOD;
    if (ssize(coaches) == 0) {
        cout << "0\n";
        return 0;
    }
    V<array<int, 3>> events1(ssize(coaches)), events2(ssize(coaches));
    for (int i = 0; i < ssize(coaches); i++) {
        events1[i] = {coaches[i], i, 0};
        events2[i] = {coaches[i] + d + 1, i, 1};
    }
    V<array<int, 3>> events(2 * ssize(coaches));
    merge(begin(events1), end(events1), begin(events2), end(events2), begin(events));
    int ptr1 = 0, ptr2 = 0;
    // ptr1 = first camper with pos >= cur, ptr2 = first camper with pos > cur + d
    while (ptr1 < ssize(campers) && campers[ptr1] < coaches[0])
        ptr1++;
    while (ptr2 < ssize(campers) && campers[ptr2] <= coaches[0] + d)
        ptr2++;
    V<ll> dp;
    dp.push_back(pow2[ptr2 - ptr1]);
    ll sum1 = 0, sum2 = 1;
    // sum1 = sum of all dp[i] for interval i nonintersecting current
    // sum2 = sum of all dp[i] * 2**-intersect(i, j) for interval i intersecting current
    for (int i = 1; i < ssize(events); i++) {
        int t = events[i][0];
        int removed = 0;
        while (ptr1 < ssize(campers) && campers[ptr1] < t) {
            ptr1++;
            removed++;
        }
        while (ptr2 < ssize(campers) && campers[ptr2] <= t + d)
            ptr2++;
        (sum2 *= pow2[removed]) %= MOD;
        if (events[i][2] == 0) {
            int c = ptr2 - ptr1;
            int res = (sum1 + sum2 + 1) * pow2[c] % MOD;
            dp.push_back(res);
            (sum2 += res * ipow2[c]) %= MOD;
        } else {
            (sum2 += MOD - dp[events[i][1]]) %= MOD;
            (sum1 += dp[events[i][1]]) %= MOD;
        }
    }
    ll ans = 0;
    for (ll i : dp)
        (ans += i) %= MOD;
    cout << ans << '\n';
    return 0;
}
