// created: 06-26-2023 Mon 04:16 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void ckmax(int& a, int b) { a = max(a, b); }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> dp(n+1, V<int>(n, -1)); // dp[i][j] = length of LIS with i uncolored segments, ending at j
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) dp[0][i] = dp[0][i-1] + 1;
        else break;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            // continue current segment
            if (dp[i][j-1] != -1 && a[j] > a[j-1]) ckmax(dp[i][j], dp[i][j-1] + 1);
            // make a new segment
            for (int k = 0; k < j-1; k++) {
                if (dp[i-1][k] != -1 && a[j] > a[k]) ckmax(dp[i][j], dp[i-1][k] + 1);
            }
            // 1 only - make first segment
            if (i == 1) ckmax(dp[i][j], 1);
        }
    }
    int ans = n;
    if (dp[0][n-1] == n) ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, n - max(*max_element(dp[i-1].begin(), prev(dp[i-1].end())), dp[i][n-1]));
        cout << ans << " \n"[i == n];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
