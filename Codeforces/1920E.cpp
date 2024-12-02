// created: 11-29-2024 Fri 11:20 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;
void mod_add(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void solve() {
    // rephrased problem: how many sequences of nonnegative integers satisfy
    // a_i + a_(i+1) + 1 <= k
    // and sum (a_i + 1) * (a_(i+1) + 1) = n
    int n, k; cin >> n >> k;
    V<V<int>> dp(n+1, V<int>(k, 0));
    // dp[i][j] = number of sequences with above sum i, last elem j
    for (int i = 0; i < k; i++) dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l + j + 1 <= k && (l + 1) * (j + 1) <= i; l++) {
                mod_add(dp[i][j], dp[i-(l+1)*(j+1)][l]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) mod_add(ans, dp[n][i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
