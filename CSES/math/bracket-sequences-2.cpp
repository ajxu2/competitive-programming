// created: 05-22-2024 Wed 10:09 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

struct Mint {
    ll v;
    static const int MOD = 1'000'000'007;
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int len; cin >> len;
    string s; cin >> s;
    int pref = 0;
    for (char i : s) {
        pref += i == '(' ? 1 : -1;
        if (pref < 0) {
            cout << "0\n";
            return 0;
        }
    }
    int remaining = len - s.length();
    if (remaining % 2 != pref % 2 || remaining < pref) {
        cout << "0\n";
        return 0;
    }
    int m = remaining - pref >> 1, n = remaining + pref >> 1;
    V<Mint> fact(m+n+1), ifact(m+n+1); fact[0] = 1;
    for (int i = 1; i <= m+n; i++) fact[i] = fact[i-1] * i;
    ifact[m+n] = inv(fact[m+n]);
    for (int i = m+n-1; i >= 0; i--) ifact[i] = ifact[i+1] * (i+1);
    cout << Mint(n-m+1) / (n+1) * fact[m+n] * ifact[m] * ifact[n] << '\n';
    return 0;
}
