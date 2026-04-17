// created: 01-22-2026 Thu 12:52 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<int, 3>> a(n);
    for (auto& [x, y, z] : a)
        cin >> x >> y >> z;
    V<array<int, 3>> dp(n, {0, 0, 0});
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k != j)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans = max(ans, dp[n - 1][i]);
    cout << ans << '\n';
    return 0;
}
