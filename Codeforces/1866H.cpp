// created: 12-08-2023 Fri 08:22 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

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

const int MX = 200'000;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<Mint> fac(MX+2), ifac(MX+2);
    fac[0] = 1; for (int i = 1; i <= MX+1; i++) fac[i] = fac[i-1] * i;
    ifac[MX+1] = inv(fac[MX+1]); for (int i = MX; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1);
    V<Mint> stuff(n+1); // answers for n = at most 0, 1, ...
    for (int i = 0; i <= n; i++) {
        if (k > i) stuff[i] = pow(Mint(i+1), k-i) * fac[i+1];
        else stuff[i] = fac[k+1];
    }
    Mint ans = stuff[0];
    for (int i = 1; i <= n; i++) ans += (stuff[i] - stuff[i-1]) * fac[n] * ifac[n-i];
    cout << ans << "\n";
    return 0;
}
