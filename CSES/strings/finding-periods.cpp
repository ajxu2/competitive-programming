// created: 10-24-2022 Mon 07:08 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string s; cin >> s;
    int n = s.length();
    ll MOD = 1e9 + 9, B = 9973;
    vector<ll> pow(n), hsh(n);
    pow[0] = 1;
    for (int i = 1; i < n; i++) {
        pow[i] = pow[i-1] * B % MOD;
    }
    hsh[0] = s[0];
    for (int i = 1; i < n; i++) {
        hsh[i] = (hsh[i-1] * B + s[i]) % MOD;
    }
    auto hash = [&](int i, int j) {
        // hash of substr [i, j]
        if (i == 0) return hsh[j];
        ll res = (hsh[j] - hsh[i-1] * pow[j-i+1]) % MOD;
        return res < 0 ? res + MOD : res;
    };
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = i; j < n; j += i) {
            int len = min(i, n-j);
            ok &= (hash(0, len-1) == hash(j, j+len-1));
        }
        if (ok) cout << i << " ";
    }
    cout << "\n";
    return 0;
}
