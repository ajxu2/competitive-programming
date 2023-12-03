// created: 12-03-2023 Sun 01:53 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 1'000'000'007;

V<ll> hsh(string s, int B) {
    V<ll> res(ssize(s));
    res[0] = s[0];
    for (int i = 1; i < ssize(s); i++) res[i] = (res[i-1] * B + s[i]) % MOD;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<string> a(n);
    ll su = 0;
    for (string& i : a) {
        cin >> i;
        su += ssize(i);
    }
    map<array<int, 2>, int> freq; // (hash1, hash2)
    int B1 = chrono::steady_clock::now().time_since_epoch().count() % MOD, B2 = chrono::steady_clock::now().time_since_epoch().count() % MOD;
    for (string i : a) {
        string j = i;
        reverse(begin(j), end(j));
        V<ll> hsh1 = hsh(j, B1), hsh2 = hsh(j, B2);
        for (int k = 0; k < ssize(j); k++) {
            array<int, 2> tmp{hsh1[k], hsh2[k]};
            freq[tmp]++;
        }
    }
    ll ans = 0;
    for (string i : a) {
        V<ll> hsh1 = hsh(i, B1), hsh2 = hsh(i, B2);
        for (int j = 0; j < ssize(i); j++) {
            array<int, 2> tmp{hsh1[j], hsh2[j]};
            if (freq.contains(tmp)) ans += freq[tmp];
        }
    }
    cout << 2 * (n * su - ans) << "\n";
    return 0;
}
