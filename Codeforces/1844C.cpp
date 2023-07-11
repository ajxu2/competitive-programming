// created: 07-11-2023 Tue 01:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    array<V<int>, 2> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i%2].push_back(x);
    }
    if (n == 1) {
        cout << a[0][0] << "\n";
        return;
    }
    ll ans = -1e18;
    for (int i = 0; i < 2; i++) {
        ll sum = 0;
        for (int j : a[i]) sum += max(0, j);
        if (sum == 0) sum = *max_element(a[i].begin(), a[i].end());
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
