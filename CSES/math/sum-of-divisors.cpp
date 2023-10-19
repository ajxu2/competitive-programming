// created: 10-19-2023 Thu 09:41 AM
 
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
	ll n; cin >> n;
	int s = (int)sqrt(n);
	Mint ans = 0;
	for (int i = 1; i <= s; i++) {
		// floor(n/x) = y -> x ranges from floor(n/(y+1)) ex to floor(n/y) in
		ll l = n / (i+1), r = n / i;
		Mint sum = Mint(l + r) * (r - l + 1) / 2;
		sum -= l; sum *= i; ans += sum;
	}
	for (int i = n / (s+1); i >= 1; i--) ans += i * (n/i);
	cout << ans << "\n";
	return 0;
}
