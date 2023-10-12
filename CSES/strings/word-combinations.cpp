// created: 10-09-2023 Mon 09:20 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 1'000'000'007;

struct HashedString {
    static const ll MOD = 1'000'000'007;
    V<ll> pow, hsh;
    int n;
    HashedString() {}
    HashedString(string s) {
        n = sz(s);
        static const ll B = chrono::steady_clock::now().time_since_epoch().count() % MOD;
        pow.resize(n); pow[0] = 1;
        for (int i = 1; i < n; i++) pow[i] = pow[i-1] * B % MOD;
        hsh.resize(n); hsh[0] = s[0];
        for (int i = 1; i < n; i++) hsh[i] = (hsh[i-1] * B + s[i]) % MOD;
    }
    ll substr(int i, int j) {
        j = min(i + j, n);
        if (i == 0) return hsh[j-1];
        ll res = (hsh[j-1] - pow[j-i] * hsh[i-1]) % MOD;
        return res < 0 ? res + MOD : res;
    }
    friend istream& operator>>(istream& s, HashedString& hs) {
        string st; s >> st;
        hs = HashedString(st);
        return s;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    HashedString s; cin >> s;
    int n = s.n;
    int k; cin >> k;
    V<array<int, 2>> a(k);
    V<int> lengths(k);
    for (int i = 0; i < k; i++) {
        HashedString tmp; cin >> tmp;
        a[i] = {tmp.substr(0, tmp.n), tmp.n};
        lengths[i] = tmp.n;
    }
    sort(begin(a), end(a));
    sort(begin(lengths), end(lengths));
    lengths.erase(unique(begin(lengths), end(lengths)), end(lengths));
    auto chk = [&](array<int, 2> x) {
        return *lower_bound(begin(a), end(a), x) == x;
    };
    V<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        array<int, 2> search = {s.substr(0, i+1), i+1};
        if (chk(search)) dp[i] = (dp[i] + 1) % MOD;
        for (int j : lengths) {
            if (j >= i+1) continue;
            search = {s.substr(i-j+1, j), j};
            if (chk(search)) dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    cout << dp[n-1] << "\n";
    return 0;
}
