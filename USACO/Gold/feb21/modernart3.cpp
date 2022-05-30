// created: 05-29-2022 Sun 02:35 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            for (int k = 0; k < i; k++) {
                dp[j][j+i] = min(dp[j][j+i], dp[j][j+k]+dp[j+k+1][j+i]-(a[j]==a[j+i]));
            }
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}
