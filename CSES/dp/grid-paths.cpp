// created: 05-24-2022 Tue 06:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<vector<bool>> a(n+1, vector<bool>(n+1, false));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '*') a[i+1][j+1] = true;
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    if (a[1][1]) dp[1][1] = 0;
    else dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            if (a[i][j]) dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}
