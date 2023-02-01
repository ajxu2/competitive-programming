// created: 02-01-2023 Wed 10:14 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998244353;

ll fexp(ll a, int b) {
    ll ans = 1;
    while (b > 0) {
        if (b&1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a) {
    return fexp(a, MOD-2);
}

ll frac(ll a, ll b) {
    return (a * inv(b)) % MOD;
}

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    V<ll> plus(n+1); plus[n] = 1;
    for (int i = n-1; i >= 1; i--) {
        ll tmp = ((frac(n-i, n) * plus[i+1]) % MOD + 1) % MOD;
        tmp = (tmp * frac(n, i)) % MOD;
        plus[i] = tmp;
    }
    int ed = 0;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) ed++;
    ll ans = 0;
    for (int i = 1; i <= ed; i++) ans = (ans + plus[i]) % MOD;
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
