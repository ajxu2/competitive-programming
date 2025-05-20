// created: 05-19-2025 Mon 06:02 PM
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
template<class T> using V = vector<T>;
 
bool is_prime(ll x) {
    if (x <= 2)
        return x == 2;
    if (x % 2 == 0)
        return false;
    for (ll i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}
 
void solve() {
    ll n; cin >> n; n++;
    while (!is_prime(n))
        n++;
    cout << n << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
