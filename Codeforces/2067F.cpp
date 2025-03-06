// created: 03-05-2025 Wed 12:31 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    // at each step, our "lone" number is always a1+a2+...+an
    // so the only thing we need to keep track of is the other thing
    map<int, ll> m; m[0] = 1;
    int x = 0;
    for (int i : a) {
        m[x] = (3 * m[x] + 2 * m[x ^ i]) % MOD;
        x ^= i;
    }
    ll ans = 0;
    for (auto [k, v] : m) ans += v;
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
