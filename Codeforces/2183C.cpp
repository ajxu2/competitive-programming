// created: 01-07-2026 Wed 09:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int l = k - 1, r = n - k;
    if (l > r)
        swap(l, r);
    int days = -1, ans = 1;
    for (int i = 0; i < l; i++) {
        if (days + 2 > m)
            goto done;
        days += 2;
        ans++;
        if (days + 1 > m)
            goto done;
        days++;
        ans++;
    }
    for (int i = 0; i < r - l; i++) {
        if (days + 2 > m)
            goto done;
        days += 2;
        ans++;
    }
    done:;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
