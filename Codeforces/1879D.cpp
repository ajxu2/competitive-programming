// created: 09-24-2023 Sun 10:40 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 998244353;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    if (n == 1) {
        cout << a[0] % MOD << "\n";
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i <= 30; i++) {
        V<short> b(n);
        for (int j = 0; j < n; j++) b[j] = (a[j] >> i) & 1;
        V<ll> pfx(n), sfx(n); // number of subarrays ending at i with set bit
        pfx[0] = b[0];
        for (int i = 1; i < n; i++) {
            if (b[i] == 0) pfx[i] = pfx[i-1];
            else pfx[i] = i + 1 - pfx[i-1];
        }
        sfx[n-1] = b[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (b[i] == 0) sfx[i] = sfx[i+1];
            else sfx[i] = n - i - sfx[i+1];
        }
        ll tmpans = 0;
        tmpans += sfx[0];
        tmpans += pfx[n-1];
        tmpans %= MOD;
        for (int i = 1; i <= n-2; i++) {
            tmpans += pfx[i] * (n - i - 1 - sfx[i+1]); tmpans %= MOD;
            tmpans += (i + 1 - pfx[i]) * sfx[i+1]; tmpans %= MOD;
            tmpans += pfx[i]; tmpans %= MOD;
        }
        tmpans <<= i; tmpans %= MOD;
        ans += tmpans; ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
