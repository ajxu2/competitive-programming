// created: 05-24-2022 Tue 08:21 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i <= a.length(); i++) {
        for (int j = 0; j <= b.length(); j++) {
            if (i == 0 && j == 0) continue;
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
        }
    }
    cout << dp.back().back() << "\n";
    return 0;
}
