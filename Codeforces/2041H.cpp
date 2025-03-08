// created: 03-08-2025 Sat 03:09 PM

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<Mint> fac(n); fac[0] = 1;
    for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i;
    V<Mint> ifac(n); ifac[n-1] = inv(fac[n-1]);
    for (int i = n-2; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1);
    auto binom = [&](int n, int k) { return fac[n] * ifac[k] * ifac[n-k]; };
    if (k == 1) {
        cout << "1\n";
        return 0;
    }
    // main idea: remove the -s, then it's the number of ways to tile a line
    // with tiles of size 1, 2, ..., k-1
    V<Mint> dp(n); dp[0] = 1;
    Mint window_sum = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = window_sum;
        window_sum += dp[i];
        if (i-(k-1) >= 0) window_sum -= dp[i-(k-1)];
    }
    Mint ans = 0;
    for (int i = 0; i <= n-1; i++) {
        Mint cnt = dp[i];
        if (i != 0) cnt *= 2;
        ans += cnt * binom(n-1, i);
    }
    cout << ans << '\n';
    return 0;
}
