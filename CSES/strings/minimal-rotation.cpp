// created: 11-19-2023 Sun 12:23 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

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
    string s; cin >> s;
    int n = sz(s);
    s += s;
    HashedString hs(s);
    auto cmp = [&](int i, int j) {
        // true if substr at i < substr at j
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (hs.substr(i, mid) == hs.substr(j, mid)) l = mid;
            else r = mid - 1;
        }
        if (l == n) return false;
        else return s[i+l] < s[j+l];
    };
    int ans = 0;
    for (int i = 1; i < n; i++) if (cmp(i, ans)) ans = i;
    cout << s.substr(ans, n) << "\n";
    return 0;
}
