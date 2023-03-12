// created: 03-12-2023 Sun 09:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int a, b; cin >> a >> b;
    a = abs(a); b = abs(b);
    if (a > b) swap(a, b);
    int ans = 2 * a;
    if (a != b) ans += 2 * (b - a) - 1;
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
