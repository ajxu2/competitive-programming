// created: 10-22-2023 Sun 05:26 PM

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

V<V<Mint>> operator*(const V<V<Mint>>& a, const V<V<Mint>>& b) {
    // assume a = n * p, b = p * m
    int n = sz(a), p = sz(a[0]), m = sz(b[0]);
    V<V<Mint>> res(n, V<Mint>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

V<V<Mint>>& operator*=(V<V<Mint>>& a, const V<V<Mint>>& b) { return a = a * b; }

V<V<Mint>> pow(V<V<Mint>> a, ll b) {
    // only for square matrices
    int n = sz(a);
    V<V<Mint>> res(n, V<Mint>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a; b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    V<V<Mint>> a(n, V<Mint>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        a[u][v]++;
    }
    cout << pow(a, k)[0][n-1] << "\n";
    return 0;
}
