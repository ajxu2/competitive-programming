// created: 06-03-2023 Sat 09:53 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<V<int>> a(n+1);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end(), greater<int>());
        for (int j = 0; j < min(i, (int)a[i].size()); j++) ans += a[i][j];
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
