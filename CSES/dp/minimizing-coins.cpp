#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> dp(x+1, INT_MAX - 1);
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        if (w[i] <= x) {
            dp[w[i]] = 1;
        }
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - w[j] > 0 && dp[i] != 1) {
                dp[i] = min(dp[i], dp[i-w[j]]+1);
            }
        }
    }
    if (dp[x] == INT_MAX - 1) {
        cout << "-1\n";
    } else {
        cout << dp[x] << "\n";
    }
    return 0;
}
