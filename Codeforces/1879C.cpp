// created: 09-24-2023 Sun 09:49 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 998244353;

array<ll, 200001> fac;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    char cur = s[0]; int cnt = 1;
    V<int> chunks;
    for (int i = 1; i < n; i++) {
        if (s[i] != cur) {
            chunks.push_back(cnt);
            cur = s[i]; cnt = 1;
        } else cnt++;
    }
    chunks.push_back(cnt);
    ll ans = 1;
    for (int i : chunks) ans = ans * i % MOD;
    ans = ans * fac[n - sz(chunks)] % MOD;
    cout << n - sz(chunks) << " " << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = fac[i-1] * i % MOD;
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
