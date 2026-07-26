// created: 07-25-2026 Sat 08:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<ll> a(n);
    for (ll& i : a)
        cin >> i;
    V<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
    V<ll> sums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i <= (n + 1) / 2)
            sums[i] = (sums[i - 1] + p[n + 1 - i] - p[i - 1]) % MOD;
        else
            sums[i] = sums[n + 1 - i];
    }
    V<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        (ans += sums[i] * inv[i]) %= MOD;
    cout << ans << '\n';
    return 0;
}
