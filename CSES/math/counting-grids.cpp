// created: 10-21-2023 Sat 12:06 AM

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
    Mint& operator/=(const Mint& o) { return (*this *= inv(o)); }
    friend Mint pow(Mint a, ll b) {
        Mint res = 1;
        while (b > 0) {
            if (b & 1) res *= a;
            a *= a; b >>= 1;
        }
        return res;
    }
    friend Mint inv(const Mint& a) { return pow(a, MOD-2); }
    Mint& operator++() { return (*this += 1); }
    Mint operator++(int) { Mint old = *this; operator++(); return old; }
    Mint& operator--() { return (*this -= 1); }
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
    ll n; cin >> n;
    Mint four, two, one;
    if (n % 2 == 0) {
        four = pow(Mint(2), n*n/4);
        two = pow(Mint(2), n*n/2) - four;
        one = pow(Mint(2), n*n) - four - two;
    } else {
        four = pow(Mint(2), n/2*(n/2+1)+1);
        two = pow(Mint(2), n/2*(n/2+1)*2+1) - four;
        one = pow(Mint(2), n*n) - four - two;
    }
    cout << four + two / 2 + one / 4 << "\n";
    return 0;
}
