// created: 04-18-2025 Fri 01:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;
const int INV4 = 748'683'265;
ll c2(ll x) { return x * (x - 1) / 2 % MOD; }

void solve() {
    // key idea: replace 0 with -1, then use ivt to reason that the score of
    // any binary string v is |v|^2/4 (minus 1/4 if |v| is odd) then free
    int n, q; cin >> n >> q;
    V<ll> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; i++)
        pow2[i] = pow2[i-1] * 2 % MOD;
    string s; cin >> s;
    V<bool> bits(n, false);
    int num_ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            bits[i] = true;
            num_ones++;
        }
    }
    while (q--) {
        int i; cin >> i; i--;
        if (bits[i]) {
            bits[i] = false;
            num_ones--;
        } else {
            bits[i] = true;
            num_ones++;
        }
        // calculate sum of squares of sums of subsequences
        ll res = n * pow2[n-1] % MOD;
        res += c2(num_ones) * pow2[n-1]; res %= MOD;
        res += c2(n - num_ones) * pow2[n-1]; res %= MOD;
        res -= (ll)num_ones * (n - num_ones) % MOD * pow2[n-1]; res %= MOD;
        res -= pow2[n-1]; res %= MOD;
        res *= INV4; res %= MOD;
        if (res < 0) res += MOD;
        cout << res << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
