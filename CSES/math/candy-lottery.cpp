// created: 10-23-2023 Mon 11:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<V<double>> dp(n, V<double>(k+1, 0));
    for (int i = 1; i <= k; i++) dp[0][i] = 1. / k;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] += dp[i-1][j] * j / k;
            for (int l = 1; l < j; l++) dp[i][j] += dp[i-1][l] / k;
        }
    }
    double ans = 0;
    for (int i = 1; i <= k; i++) ans += i * dp[n-1][i];
    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}
