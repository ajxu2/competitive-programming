// created: 06-25-2024 Tue 10:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    V<int> a(n);
    for (int& i : a) cin >> i;
    ll cur = 0;
    int ans = 0, lptr = 0;
    for (int rptr = 0; rptr < n; rptr++) {
        cur += a[rptr];
        while (cur > r) cur -= a[lptr++];
        if (l <= cur && cur <= r) {
            cur = 0; lptr = rptr + 1; ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
