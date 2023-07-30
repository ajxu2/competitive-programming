// created: 07-29-2023 Sat 10:19 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

const int MOD = 998244353;
const int MX = 1000000;

ll fexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return res;
}

ll inv(ll a) { return fexp(a, MOD-2); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    V<bool> prime(MX+1, 1);
    prime[0] = 0; prime[1] = 0;
    for (int i = 2; i <= MX; i++) {
        if (!prime[i]) continue;
        for (int j = 2*i; j <= MX; j += i) {
            prime[j] = 0;
        }
    }
    V<ll> fact(MX, 1);
    for (int i = 1; i <= MX; i++) fact[i] = fact[i-1] * i % MOD;
    V<ll> ifact(MX); ifact[MX] = inv(fact[MX]);
    for (int i = MX-1; i >= 0; i--) ifact[i] = ifact[i+1] * (i+1) % MOD;
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    V<int> freqp;
    ll ans = fact[n];
    for (pair<int, int> i : freq) {
        if (prime[i.first]) freqp.push_back(i.second);
        ans = ans * ifact[i.second] % MOD;
    }
    if (sz(freqp) < n) {
        cout << "0\n";
        return 0;
    }
    V<V<ll>> dp(sz(freqp)+1, V<ll>(sz(freqp)+1)); // dp[i][j] = sum products of choices of j elements of first i
    dp[1][0] = 1; dp[1][1] = freqp[0];
    for (int i = 2; i <= sz(freqp); i++) {
        dp[i][0] = 1; dp[i][i] = dp[i-1][i-1] * freqp[i-1] % MOD;
        for (int j = 1; j < sz(freqp); j++) dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] * freqp[i-1]) % MOD;
    }
    ans = ans * dp[sz(freqp)][n] % MOD;
    cout << ans << "\n";
    return 0;
}
