// created: 05-24-2022 Tue 06:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(1000001, 0);
    dp[0] = 1;
    for (int i : a) {
        for (int j = 1; j <= x; j++) {
            if (j-i >= 0) {
                dp[j] += dp[j-i];
                dp[j] %= 1000000007;
            }
        }
    }
    cout << dp[x] << "\n";
    return 0;
}
