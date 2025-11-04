// created: 08-30-2025 Sat 08:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll f(ll x) {
    ll res = 0;
    while (x > 0) {
        int dig = x % 10;
        res *= 10;
        res += dig;
        x /= 10;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    V<ll> a(10); cin >> a[0] >> a[1];
    for (int i = 2; i < 10; i++)
        a[i] = f(a[i-1] + a[i-2]);
    cout << a.back() << '\n';
    return 0;
}
