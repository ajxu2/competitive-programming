// created: 05-13-2025 Tue 03:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    ll ans = 1;
    for (auto [k, v] : mp)
        ans = ans * (v + 1) % MOD;
    ans += MOD - 1;
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
