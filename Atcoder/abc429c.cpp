// created: 10-25-2025 Sat 08:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    for (auto [_, f] : mp) {
        if (f >= 2)
            ans += (ll)f * (f - 1) * (n - f) / 2;
    }
    cout << ans << '\n';
    return 0;
}
