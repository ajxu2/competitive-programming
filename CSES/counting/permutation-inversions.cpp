// created: 10-29-2024 Tue 09:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

void mod_add(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mod_sub(int& a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<V<int>> dp(n+1, V<int>(k+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j <= k; j++) {
            mod_add(sum, dp[i-1][j]);
            if (j >= i) mod_sub(sum, dp[i-1][j-i]);
            dp[i][j] = sum;
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}
