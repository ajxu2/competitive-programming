// created: 11-22-2025 Sat 07:32 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<int> x(n), y(m);
    for (int& i : x)
        cin >> i;
    for (int& i : y)
        cin >> i;
    V<array<int, 4>> constraints; // (bound, abs diff, x, y)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            constraints.push_back({min(x[i], y[j]), abs(x[i] - y[j]), i, j});
    sort(begin(constraints), end(constraints));
    set<int> remaining;
    for (int i = 1; i <= n * m; i++)
        remaining.insert(i);
    V<V<int>> ans(n, V<int>(m));
    for (auto [bound, diff, i, j] : constraints) {
        auto it = remaining.upper_bound(bound);
        if (it == begin(remaining)) {
            cout << "No\n";
            return;
        }
        it = prev(it);
        ans[i][j] = *it;
        remaining.erase(it);
    }
    for (int i = 0; i < n; i++) {
        int mx = *max_element(begin(ans[i]), end(ans[i]));
        if (mx != x[i]) {
            cout << "No\n";
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        int mx = 0;
        for (int j = 0; j < n; j++)
            mx = max(mx, ans[j][i]);
        if (mx != y[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
