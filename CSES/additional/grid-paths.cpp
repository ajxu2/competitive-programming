// created: 10-16-2024 Wed 08:19 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

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
    int n, m; cin >> n >> m;
    V<array<int, 2>> traps(m);
    for (array<int, 2>& i : traps) cin >> i[0] >> i[1];
    V<Mint> fac(2*n), ifac(2*n);
    fac[0] = 1;
    for (int i = 1; i < 2*n; i++) fac[i] = fac[i-1] * i;
    ifac[2*n-1] = inv(fac[2*n-1]);
    for (int i = 2*n-2; i >= 0; i--) ifac[i] = ifac[i+1] * Mint(i+1);
    auto binom = [&](int n, int k) -> Mint { return fac[n] * ifac[k] * ifac[n-k]; };
    auto paths = [&](int dx, int dy) -> Mint { return binom(dx + dy, dy); };
    // janky PIE stuff
    sort(begin(traps), end(traps));
    V<Mint> dp(m);
    for (int i = m-1; i >= 0; i--) {
        dp[i] = paths(n - traps[i][0], n - traps[i][1]);
        for (int j = i+1; j < m; j++) {
            if (traps[j][1] < traps[i][1]) continue;
            dp[i] -= paths(traps[j][0] - traps[i][0], traps[j][1] - traps[i][1]) * dp[j];
        }
    }
    Mint ans = paths(n-1, n-1);
    for (int i = 0; i < m; i++) ans -= paths(traps[i][0] - 1, traps[i][1] - 1) * dp[i];
    cout << ans << '\n';
    return 0;
}
