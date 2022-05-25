// created: 05-24-2022 Tue 02:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && i-j >= 0; j++) {
            dp[i] += dp[i-j]; dp[i] %= 1000000007;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
