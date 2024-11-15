// created: 10-23-2024 Wed 04:12 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) { cin >> i; i--; }
    V<ll> pow2(n+1); pow2[0] = 1;
    for (int i = 1; i <= n; i++) pow2[i] = pow2[i-1] * 2 % MOD;
    V<V<ll>> dp(n, V<ll>(n+1, 0));
    V<V<ll>> suf(n, V<ll>(n+1, 0));
    dp[0][1] = 1;
    suf[0][1] = 1;
    suf[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = pow2[j-2] * (a[i] > a[i-1] ? suf[i-1][j-1] : suf[i-1][j]) % MOD;
        }
        suf[i][n] = dp[i][n];
        for (int j = n-1; j >= 0; j--) suf[i][j] = (suf[i][j+1] + dp[i][j]) % MOD;
    }
    cout << suf[n-1][0] << '\n';
    return 0;
}
