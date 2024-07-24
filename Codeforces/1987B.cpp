// created: 07-22-2024 Mon 09:38 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<int> diff(n, 0);
    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) continue;
        diff[i] = a[i-1] - a[i]; a[i] = a[i-1];
    }
    ll ans = accumulate(begin(diff), end(diff), 0LL) + *max_element(begin(diff), end(diff));
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
