// created: 01-23-2026 Fri 01:37 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    V<V<int>> dp(n, V<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '<') {
            dp[i][0] = 0;
            for (int j = 1; j <= i; j++)
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
        } else {
            dp[i][i] = 0;
            for (int j = i - 1; j >= 0; j--)
                dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
        }
    }
    cout << accumulate(begin(dp[n - 1]), end(dp[n - 1]), 0LL) % MOD << '\n';
    return 0;
}
