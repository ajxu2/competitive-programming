// created: 09-15-2023 Fri 05:20 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 1'000'000'007;

void solve() {
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> dp(n, V<int>(n+1, 0)); // dp[i][j] = number of paths length j ending at index i
    for (int i = 0; i < n; i++) dp[i][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= n; j++) {
            for (int l = 0; l < i; l++) {
                if (a[l] != a[i] && (j-1) % k != 0) continue;
                dp[i][j] = (dp[i][j] + dp[l][j-1]) % MOD;
            }
            //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << "\n";
        }
    }
    for (int i = n; i >= 1; i--) {
        if (i % k != 0) continue;
        int sum = 0;
        for (int j = 0; j < n; j++) sum = (sum + dp[j][i]) % MOD;
        if (sum != 0) {
            cout << sum << "\n";
            return;
        }
    }
    cout << "1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
