// created: 06-13-2026 Sat 09:19 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    ll a, b, x, y; cin >> a >> b >> x >> y;
    x = abs(x), y = abs(y);
    bool last_move_high_cost = (x < y && a < b) || (x > y && a > b);
    if (a > b)
        swap(a, b);
    if (x > y)
        swap(x, y);
    ll ans = x * 2 * a + (y - x) / 2 * min(4 * a, a + b);
    if ((y - x) % 2 == 1) {
        if (last_move_high_cost)
            ans += min(3 * a, b);
        else
            ans += a;
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
