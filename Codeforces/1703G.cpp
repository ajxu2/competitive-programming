#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(31)); // a[i][j] = value at position i after j bad keys
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        for (int j = 1; j < 31; j++) a[i][j] = a[i][j-1]/2;
    }
    vector<vector<ll>> dp(n, vector<ll>(31)); // dp[i][j] = maximum profit to box at position i after j bad keys used
    dp[0][0] = a[0][0]-k; dp[0][1] = a[0][1];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0]+a[i][0]-k;
        for (int j = 1; j <= i+1 && j < 31; j++) {
            dp[i][j] = max(dp[i-1][j]+a[i][j]-k, dp[i-1][j-1]+a[i][j]);
        }
        if (i >= 30) dp[i][30] = max(dp[i][30], dp[i-1][30]);
    }
    ll ans = -1e18;
    for (int i = 0; i < 31; i++) ans = max(ans, dp[n-1][i]);
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
