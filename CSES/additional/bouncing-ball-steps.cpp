// created: 01-01-2026 Thu 02:12 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll position(ll n, ll k) {
    return -abs(k % (2 * n - 2) - (n - 1)) + n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        ll n, m, k; cin >> n >> m >> k;
        cout << position(n, k) << ' ' << position(m, k) << ' ' << k / (n - 1) + k / (m - 1) - k / lcm(n - 1, m - 1) << '\n';
    }
    return 0;
}
