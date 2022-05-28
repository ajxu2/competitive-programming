// created: 05-27-2022 Fri 10:54 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifndef LOCAL
    ifstream cin("248.in");
    ofstream cout("248.out");
#endif
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = a[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            for (int k = 0; k < i; k++) {
                if (dp[j][j+k] == dp[j+k+1][j+i] && dp[j][j+k] != 0) dp[j][j+i] = dp[j][j+k]+1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = max(ans, dp[i][j]);
    cout << ans << "\n";
    return 0;
}
