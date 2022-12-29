// created: 12-25-2022 Sun 09:13 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int n;
V<int> h;

int solve() {
    V<V<int>> dp(n, V<int>(1001, 0)); // dp[i][j] = answer for elements up to i, with h[i] - h[i-1] + ... = j
    V<V<int>> p(n, V<int>(1001, 0));
    for (int i = 0; i <= h[0]; i++) dp[0][i] = 1;
    p[0][0] = dp[0][0];
    for (int i = 1; i <= 1000; i++) p[0][i] = dp[0][i] + p[0][i-1];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= h[i]; j++) {
            dp[i][j] += p[i-1][h[i]-j];
            if (dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
        p[i][0] = dp[i][0];
        for (int j = 1; j <= 1000; j++) {
            p[i][j] = dp[i][j] + p[i][j-1];
            if (p[i][j] >= MOD) p[i][j] -= MOD;
        }
    }
    return dp[n-1][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; h.resize(n);
    for (int& i : h) cin >> i;
    if (n % 2 == 0) cout << solve() << "\n";
    else {
        // brute force over all final values
        int ans = 0;
        for (int i = 0; i <= 1000; i++) {
            ans += solve();
            if (ans >= MOD) ans -= MOD;
            for (int j = 0; j < n; j++) h[j]--;
        }
        cout << ans << "\n";
    }
    return 0;
}
