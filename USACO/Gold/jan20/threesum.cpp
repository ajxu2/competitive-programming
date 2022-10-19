// created: 10-19-2022 Wed 12:10 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifndef LOCAL
    ifstream cin("threesum.in");
    ofstream cout("threesum.out");
#endif
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> freq(2000001, 0);
    vector<vector<ll>> dp(n, vector<ll>(n, 0)); // dp[i][j] = solution on [i, j]
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int k = 1000000-(a[i]+a[j]);
            if (k >= 0 && k <= 2000000) dp[i][j] = freq[k];
            freq[a[j]+1000000]++;
        }
        for (int j = i+1; j < n; j++) freq[a[j]+1000000] = 0; // reset to original state
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= n-i; j++) {
            dp[j][j+i-1] += dp[j][j+i-2] + dp[j+1][j+i-1] - dp[j+1][j+i-2];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        cout << dp[x-1][y-1] << "\n";
    }
    return 0;
}
