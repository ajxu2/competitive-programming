// created: 06-25-2024 Tue 09:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    while (k > 0 && x > 1) {
        int nxt = min(k, y - x % y);
        x += nxt;
        while (x % y == 0) x /= y;
        k -= nxt;
    }
    x += k % (y - 1);
    cout << x << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
