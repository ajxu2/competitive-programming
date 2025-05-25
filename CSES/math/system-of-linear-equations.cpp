// created: 05-20-2025 Tue 03:33 PM

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
    // she eliminate on my gaussian till i RREF
    int n, m; cin >> n >> m;
    // wow valarrays are useful
    V<valarray<Mint>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m+1);
        for (int j = 0; j < m+1; j++)
            cin >> a[i][j];
    }
    int pivoted = 0; // number of rows pivoted so far
    V<int> pivot_cols;
    for (int i = 0; i < m; i++) {
        int row = -1;
        for (int j = pivoted; j < n; j++) {
            if (a[j][i].v != 0) {
                row = j;
                break;
            }
        }
        if (row == -1)
            continue;
        swap(a[pivoted], a[row]);
        Mint cancel = inv(a[pivoted][i]);
        a[pivoted] *= cancel;
        for (int j = 0; j < n; j++) {
            if (j != pivoted)
                a[j] -= a[j][i] * a[pivoted];
        }
        pivoted++;
        pivot_cols.push_back(i);
    }
    // check zero rows
    for (int i = pivoted; i < n; i++) {
        if (a[i][m].v != 0) {
            cout << "-1\n";
            return 0;
        }
    }
    V<Mint> ans(m);
    for (int i = 0; i < pivoted; i++)
        ans[pivot_cols[i]] = a[i][m];
    for (Mint i : ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
