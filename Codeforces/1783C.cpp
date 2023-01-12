// created: 01-08-2023 Sun 09:30 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<array<int, 2>> a(n);
    V<int> orig(n); // orig[i] = the cost of winning against player i
    for (int i = 0; i < n; i++) {
        cin >> orig[i];
        a[i][0] = orig[i];
        a[i][1] = i;
    }
    a.push_back({0, -1});
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) a[i][0] += a[i-1][0]; // a[i][0] = cost to win i games
    V<int> pos(n);
    for (int i = 1; i <= n; i++) pos[a[i][1]] = i;
    int ans = n+1;
    for (int i = 1; i < n; i++) {
        // is it possible to win i games?
        if (a[i][0] <= m) ans = min(ans, n-i+1);
        // is it possible to win i games, also winning a game from player i?
        if (pos[i] <= i && a[i][0] <= m || pos[i] > i && a[i-1][0] + orig[i] <= m) ans = min(ans, n-i);
    }
    if (a[n][0] <= m) ans = 1;
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
