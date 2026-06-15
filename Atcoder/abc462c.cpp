// created: 06-13-2026 Sat 09:36 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<int, 2>> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y;
    sort(begin(a), end(a));
    int min_y = INF, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i][1] < min_y;
        min_y = min(min_y, a[i][1]);
    }
    cout << ans << '\n';
    return 0;
}
