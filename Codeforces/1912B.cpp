// created: 11-19-2024 Tue 10:06 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct Mint {
    ll v;
    static const int MOD = 998'244'353;
    Mint() { v = 0; }
    Mint(ll _v) { _v %= MOD; v = (_v < 0 ? _v + MOD : _v); }
    Mint& operator+=(const Mint& o) {
        v += o.v; if (v >= MOD) v -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint& o) {
        v -= o.v; if (v < 0) v += MOD;
        return *this;
    }
    Mint& operator*=(const Mint& o) {
        v *= o.v; v %= MOD;
        return *this;
    }
    Mint& operator/=(const Mint& o) { return *this *= inv(o); }
    friend Mint pow(Mint a, ll b) {
        Mint res = 1;
        while (b > 0) {
            if (b & 1) res *= a;
            a *= a; b >>= 1;
        }
        return res;
    }
    friend Mint inv(const Mint& a) { return pow(a, MOD-2); }
    Mint& operator++() { return *this += 1; }
    Mint operator++(int) { Mint old = *this; operator++(); return old; }
    Mint& operator--() { return *this -= 1; }
    Mint operator--(int) { Mint old = *this; operator--(); return old; }
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend istream& operator>>(istream& is, Mint& a) {
        ll _v; is >> _v; a = Mint(_v);
        return is;
    }
    friend ostream& operator<<(ostream& os, const Mint& a) { os << a.v; return os; }
};

const int MX = 1'000'005;
array<Mint, MX> fac, ifac;

Mint binom(int n, int k) { return fac[n] * ifac[k] * ifac[n-k]; }
Mint trinom(int n, int k1, int k2) { return binom(n, k1) * binom(n - k1, k2); }

ll value(int x) { return x % 2 == 0 ? (ll)(x / 2 - 1) * (x / 2) : (ll)(x / 2) * (x / 2); }

void solve() {
    int n, k; cin >> n >> k;
    int f = n / k, ff = k - n % k, c = n / k + 1, cf = n % k;
    Mint res = 0;
    if (f == 1) {
        res = binom(k-1, ff);
        goto bruh;
    }
    if (f % 2 == 1) {
        // c % 2 == 0
        for (int i = 0; 2 * i <= ff; i++) {
            // i occurrences of f-1, ff-2*i occurrences of f, i+cf occurrences of c
            // case f-1 gets split
            if (f-1 >= 2 && i >= 1) res += trinom(k-1, i-1, i+cf);
            // case f gets split
            if (f >= 2 && ff-2*i >= 1) res += 2 * trinom(k-1, i, i+cf);
            // case c gets split
            if (c >= 2 && i+cf >= 1) res += trinom(k-1, i, i+cf-1);
        }
    } else {
        // f % 2 == 0, c % 2 == 1
        for (int i = 0; 2 * i <= cf; i++) {
            // i+ff occurrences of f, cf-2*i occurrences of c, i occurrences of c+1
            // case f gets split
            if (f >= 2 && i+ff >= 1) res += trinom(k-1, i+ff-1, i);
            // case c gets split
            if (c >= 2 && cf-2*i >= 1) res += 2 * trinom(k-1, i+ff, i);
            // case c+1 gets split
            if (c+1 >= 2 && i >= 1) res += trinom(k-1, i+ff, i-1);
        }
    }
    bruh: cout << value(f) * ff + value(c) * cf << ' ' << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < MX; i++) fac[i] = fac[i-1] * i;
    ifac[MX-1] = inv(fac[MX-1]);
    for (int i = MX-2; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
