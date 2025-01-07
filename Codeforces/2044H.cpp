// created: 01-06-2025 Mon 04:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

class TwoDimensionalPrefixSummer { // ☀️
private:
    int n;
    V<V<ll>> ps;
public:
    template<class F> TwoDimensionalPrefixSummer(int _n, F f) {
        n = _n;
        ps = V<V<ll>>(n+1, V<ll>(n+1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ps[i+1][j+1] = ps[i+1][j] + ps[i][j+1] - ps[i][j] + f(i, j);
            }
        }
    }
    ll qry(int x1, int y1, int x2, int y2) {
        return ps[x2+1][y2+1] - ps[x2+1][y1] - ps[x1][y2+1] + ps[x1][y1];
    }
};

void solve() {
    // key idea:
    /*
        123   123       000
        456 = 123 + 3 * 111
        789   123       222
    */
    int n, q; cin >> n >> q;
    V<V<int>> a(n, V<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    TwoDimensionalPrefixSummer owo(n, [&a](int x, int y) { return a[x][y]; }),
                               uwu(n, [&a](int x, int y) { return x * a[x][y]; }),
                               iwi(n, [&a](int x, int y) { return y * a[x][y]; });
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        ll one = iwi.qry(x1, y1, x2, y2) - (y1 - 1) * owo.qry(x1, y1, x2, y2);
        ll two = uwu.qry(x1, y1, x2, y2) - x1 * owo.qry(x1, y1, x2, y2);
        cout << one + (y2 - y1 + 1) * two << " \n"[i == q-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
