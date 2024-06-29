// created: 06-25-2024 Tue 11:01 AM

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

const Mint HALF((Mint::MOD + 1) >> 1);
Mint tri(Mint x) { return x * (x + 1) * HALF; }

V<V<Mint>> dp(63, V<Mint>(63, 0)); // dp[i][j] = answer for 1 << i, exclude >= j, only valid for i >= j

void solve() {
    ll n; int k; cin >> n >> k; k++;
    Mint ans = 0;
    ll cur = 0;
    // what the hell does this do
    for (int i = 62; i >= 0 && k >= 0; i--) {
        if ((n & (1LL << i)) == 0) continue;
        if (i >= k) {
            ans += dp[i][k]; k--;
            cur += 1LL << i;
        } else {
            ans += tri(n - cur);
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    dp[0][0] = 0;
    for (int i = 1; i < 63; i++) dp[0][i] = 1;
    for (int i = 1; i < 63; i++) {
        dp[i][0] = 0;
        for (int j = 1; j < i; j++) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        dp[i][i] = tri((1LL << i) - 1);
    }
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
