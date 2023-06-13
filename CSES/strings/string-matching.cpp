// created: 10-31-2022 Mon 07:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'007;
ll B;

struct HashedString {
    // polynomial hash; hash of a string is A_0 * B^(n-1) + A_1 * B^(n-2) + ... + A_(n-1) * B^0
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
    // generate a random value of B. HACKERS, COME AT ME
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    B = rng();
    string s1, s2; cin >> s1 >> s2;
    HashedString hs1(s1), hs2(s2);
    ll hash2 = hs2.substr(0, s2.length());
    int ans = 0;
    for (int i = 0; i < s1.length()-s2.length()+1; i++) if (hs1.substr(i, i+s2.length()) == hash2) ans++;
    cout << ans << "\n";
    return 0;
}
