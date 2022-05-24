// created: 05-24-2022 Tue 02:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifndef LOCAL
    ifstream cin("time.in");
    ofstream cout("time.out");
#endif
    int n, m, c; cin >> n >> m >> c;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> badj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        badj[v].push_back(u);
    }
    vector<vector<int>> dp(n+1, vector<int>(1001, -1e9));
    // dp[x][t] = profit of ending at node x after traveling for time t
    dp[1][0] = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k : badj[j]) dp[j][i] = max(dp[j][i], dp[k][i-1] + a[j] - c*(2*i-1));
        }
    }
    int ans = -1e9;
    for (int i = 0; i <= 1000; i++) ans = max(ans, dp[1][i]);
    cout << ans << "\n";
    return 0;
}
