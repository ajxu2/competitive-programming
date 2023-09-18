// created: 09-18-2023 Mon 09:43 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, m; cin >> n >> m;
    V<int> a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    int o = accumulate(b.begin(), b.end(), 0, bit_or<int>());
    int ans1 = accumulate(a.begin(), a.end(), 0, bit_xor<int>());
    for (int& i : a) i |= o;
    int ans2 = accumulate(a.begin(), a.end(), 0, bit_xor<int>());
    if (n % 2 == 0) cout << ans2 << " " << ans1 << "\n";
    else cout << ans1 << " " << ans2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
