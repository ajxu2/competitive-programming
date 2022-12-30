// created: 12-30-2022 Fri 08:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<ll> a(n), b(m);
    for (ll& i : a) cin >> i;
    for (ll& i : b) {
        cin >> i;
        auto it = min_element(a.begin(), a.end());
        (*it) = i;
    }
    cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
