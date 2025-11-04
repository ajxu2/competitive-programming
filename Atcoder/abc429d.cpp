// created: 10-25-2025 Sat 08:10 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll m; int c; cin >> n >> m >> c;
    V<ll> a(n);
    for (ll& i : a)
        cin >> i;
    sort(begin(a), end(a));
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int idx;
        if (i > 0 && a[i] == a[i-1])
            goto addition;
        idx = (i + n - c) % n;
        sum = (a[i] - a[idx] + m - 1) % m + 1;
        addition:
        ans += sum;
    }
    cout << ans << '\n';
    return 0;
}
