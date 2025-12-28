// created: 12-27-2025 Sat 08:48 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<ll> sfx_sum(n + 1);
    sfx_sum[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        sfx_sum[i] = sfx_sum[i + 1] + a[i];
    ll pfx = 0, ans = -1e18;
    for (int i = 0; i < n; i++) {
        ans = max(ans, pfx - sfx_sum[i + 1]);
        if (i == 0)
            pfx += a[i];
        else
            pfx += (a[i] > 0 ? a[i] : -a[i]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
