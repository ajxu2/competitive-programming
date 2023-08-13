// created: 08-12-2023 Sat 10:18 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i+1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        V<int> b = a;
        reverse(b.begin() + i, b.end());
        V<int> c(n);
        for (int j = 0; j < n; j++) c[j] = b[j] * (j+1);
        ans = max(ans, accumulate(c.begin(), c.end(), 0LL) - *max_element(c.begin(), c.end()));
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
