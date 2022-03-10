// created: 03-10-2022 Thu 11:03 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, b, MOD; cin >> n >> m >> b >> MOD;
    vector<int> a(n+1); 
    for (int i = 1; i <= n; i++) cin >> a[i];
    // dp[1][2][3] = 1 programmer 2 lines code total 3 bugs
    // actually kinda not since ML is tight and we only need the previous i value we can set the array size to 2
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(m+1, vector<int>(b+1, 0)));
    dp[0][0][0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                dp[i%2][j][k] = dp[!(i%2)][j][k];
                if (j > 0 && k-a[i] >= 0) dp[i%2][j][k] += dp[i%2][j-1][k-a[i]];
                dp[i%2][j][k] %= MOD;
            }
        }
    }
    for (int i = 0; i <= b; i++) {
        ans += dp[n%2][m][i]; ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
