// created: 02-26-2022 Sat 05:11 PM

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
vector<long long> fact;

long long exp(long long a, long long b) {
    long long ans = 1;
    while (b != 0) {
        if (b % 2 == 1) {
            ans *= a;
            b--;
            ans %= MOD;
        } else {
            a *= a;
            b /= 2;
            a %= MOD;
        }
    }
    return ans;
}

long long nCr(int n, int r) {
    return fact[n]*exp(fact[r]*fact[n-r]%MOD,MOD-2)%MOD;
}

int main() {
    int n; cin >> n;
    fact.push_back(1); // 0!=1
    for (int i = 1; i <= 2*n; i++) fact.push_back(fact.back()*i%MOD);
    // number of states at depth i
    vector<int> dp(2*n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) dp[i] = (dp[i-1]*2)%MOD;
    for (int i = n+1; i <= 2*n; i++) dp[i] = (dp[i-1]*2-2*nCr(i-1,n))%MOD;
    long long ans = 0;
    for (int i = 0; i <= 2*n; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
    return 0;
}
