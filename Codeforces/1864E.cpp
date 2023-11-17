// created: 11-16-2023 Thu 10:17 PM

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

void solve() {
    int n; cin >> n;
    V<unsigned> a(n);
    for (unsigned& i : a) cin >> i;
    array<unordered_map<unsigned, unsigned>, 30> freq; // freq[i] = freq map for all >>i
    for (int i = 0; i < 30; i++) for (unsigned j : a) freq[i][j>>i]++;
    Mint ans = 0;
    ll pairs = 0;
    for (unsigned i : a) {
        ans += freq[0][i] * (popcount(i) + 1);
        for (int j = 1; j <= 30; j++) {
            // >>j is the same
            unsigned search = i >> (j-1) ^ 1;
            if (freq[j-1].find(search) != end(freq[j-1])) {
                ans += freq[j-1][search] * popcount(i>>j);
                pairs += freq[j-1][search];
            }
        }
    }
    ans += pairs / 2 * 3;
    ans /= (ll)n * n;
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
