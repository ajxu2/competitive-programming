// created: 01-06-2025 Mon 01:36 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // key idea: travel on paths with gcd 1, then dp the rest
    int n, a, b; cin >> n >> a >> b;
    auto c = [&](int x, int y) -> int { return gcd(x, a) + gcd(y, b); };
    int start_x = n, start_y = n;
    while (gcd(start_x, a) != 1) start_x--;
    while (gcd(start_y, b) != 1) start_y--;
    V<V<int>> dp(n - start_x + 1, V<int>(n - start_y + 1));
    for (int i = 0; i < n - start_x + 1; i++) {
        for (int j = 0; j < n - start_y + 1; j++) {
            dp[i][j] = c(i + start_x, j + start_y);
        }
    }
    for (int i = 0; i < n - start_x + 1; i++) {
        for (int j = 0; j < n - start_y + 1; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            int mn = numeric_limits<int>::max();
            if (i != 0) mn = min(mn, dp[i-1][j]);
            if (j != 0) mn = min(mn, dp[i][j-1]);
            dp[i][j] += mn;
        }
    }
    int ans = dp.back().back();
    for (int i = 1; i <= start_x; i++) ans += c(i, 1);
    for (int i = 2; i <= start_y; i++) ans += c(start_x, i);
    cout << ans << '\n';
    return 0;
}
