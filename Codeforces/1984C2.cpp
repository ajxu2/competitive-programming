// created: 06-09-2024 Sun 10:19 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 998'244'353;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<ll> pow2(n+1); pow2[0] = 1;
    for (int i = 1; i <= n; i++) pow2[i] = pow2[i-1] * 2 % MOD;
    V<ll> pre(n); pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i-1] + a[i];
    ll mnpre = min(0LL, *min_element(begin(pre), end(pre)));
    if (mnpre == 0) {
        cout << pow2[n] << '\n';
        return;
    }
    int cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (pre[i] >= 0) cnt++;
        if (pre[i] == mnpre) {
            ans += pow2[cnt] * pow2[n-1-i];
            ans %= MOD;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
