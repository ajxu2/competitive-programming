// created: 11-07-2022 Mon 08:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct HashedString {
    // polynomial hash; hash of a string is A_0 * B^(n-1) + A_1 * B^(n-2) + ... + A_(n-1) * B^0
    static const ll MOD = 1000000007, B = 9973;
    static inline vector<ll> pow{1}; // powers of B
    vector<ll> hsh; // hashes of prefixes
    HashedString(string s) {
        int n = s.length();
        while ((int)pow.size() < n) pow.push_back(pow.back() * B % MOD);
        hsh.push_back(s[0]);
        for (int i = 1; i < n; i++) hsh.push_back((hsh.back() * B + s[i]) % MOD);
    }
    ll substr(int i, int j) {
        // return the hash of the substring [i, j)
        if (i == 0) return hsh[j-1];
        ll res = (hsh[j-1] - pow[j-i] * hsh[i-1]) % MOD;
        return res < 0 ? res + MOD : res;
    }
};

int main() {
    string s; cin >> s;
    int n = s.length();
    HashedString hs(s);
    for (int i = 1; i < n; i++) {
        if (hs.substr(0, i) == hs.substr(n-i, n)) cout << i << " ";
    }
    cout << "\n";
    return 0;
}