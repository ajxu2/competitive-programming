// created: 05-24-2022 Tue 05:57 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(1000001, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j : a) {
            if (i-j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= 1000000007;
            }
        }
    }
    cout << dp[x] << "\n";
    return 0;
}
