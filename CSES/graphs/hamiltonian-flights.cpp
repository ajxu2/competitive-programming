// created: 05-26-2022 Thu 11:43 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> badj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        badj[b].push_back(a);
    }
    vector<vector<int>> dp(1<<n, vector<int>(n, 0));
    // dp[S][x] = number of Hamiltonian paths with nodes S that start at 0 and end at x
    dp[1][0] = 1;
    for (int i = 2; i < 1<<n; i++) {
        if ((i&1) == 0) continue;
        for (int j = 0; j < n; j++) {
            if ((i&1<<j) == 0) continue;
            for (int k : badj[j]) {
                if ((i&1<<k) == 0) continue;
                dp[i][j] += dp[i^1<<j][k];
                dp[i][j] %= 1000000007;
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << "\n";
    return 0;
}
