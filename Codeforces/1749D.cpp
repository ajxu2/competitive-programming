// created: 10-26-2022 Wed 09:42 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;

int main() {
    int n; ll m; cin >> n >> m;
    // Sieve of Eratosthenes
    vector<bool> sieve(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) continue;
        for (int j = 2*i; j <= n; j += i) sieve[j] = false;
    }
    ll unamb = 1, tot = 1, fac = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        // compute the number of *unambiguous* with length i
        // i.e. no number is relatively prime to any index below it
        // which means it must be divisible by every prime below its index
        tot = tot * (m % MOD) % MOD;
        if (sieve[i] && fac <= m) fac *= i;
        unamb = unamb * (m/fac % MOD) % MOD;
        ans = (ans + tot - unamb) % MOD;
    }
    cout << (ans < 0 ? ans + MOD : ans) << "\n";
    return 0;
}
