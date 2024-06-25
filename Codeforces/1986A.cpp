// created: 06-23-2024 Sun 09:48 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    array<int, 3> pts;
    for (int i = 0; i < 3; i++) cin >> pts[i];
    sort(begin(pts), end(pts));
    int ans = 0;
    for (int i : pts) ans += abs(pts[1] - i);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
