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
