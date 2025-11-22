// created: 11-22-2025 Sat 07:11 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int num_len(ll x) {
    int res = 0;
    while (x > 0) {
        x /= 10;
        res++;
    }
    return res;
}

int mod_negate(int x, int m) {
    return (m - x % m) % m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<ll> a(n);
    for (ll& i : a)
        cin >> i;
    array<ll, 12> pow10;
    pow10[0] = 1;
    for (int i = 1; i < 12; i++)
        pow10[i] = pow10[i - 1] * 10 % m;
    ll ans = 0;
    for (int i = 1; i < 12; i++) {
        V<ll> b, c;
        for (ll& j : a) {
            if (num_len(j) == i)
                b.push_back(j);
            c.push_back(pow10[i] * j);
        }
        map<int, int> mp;
        for (ll& j : c)
            mp[j % m]++;
        for (ll& j : b)
            ans += mp[mod_negate(j, m)];
    }
    cout << ans << '\n';
    return 0;
}
