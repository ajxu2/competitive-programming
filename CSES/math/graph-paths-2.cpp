// created: 10-22-2023 Sun 05:26 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

V<V<ll>> operator*(const V<V<ll>>& a, const V<V<ll>>& b) {
    // assume a = n * p, b = p * m
    int n = sz(a), p = sz(a[0]), m = sz(b[0]);
    V<V<ll>> res(n, V<ll>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                if (a[i][k] == -1 || b[k][j] == -1) continue;
                ll nxt = a[i][k] + b[k][j];
                if (res[i][j] == -1 || nxt < res[i][j]) res[i][j] = nxt;
            }
        }
    }
    return res;
}

V<V<ll>>& operator*=(V<V<ll>>& a, const V<V<ll>>& b) { return a = a * b; }

V<V<ll>> pow(V<V<ll>> a, ll b) {
    // only for square matrices
    int n = sz(a);
    V<V<ll>> res(n, V<ll>(n, -1));
    for (int i = 0; i < n; i++) res[i][i] = 0;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a; b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    V<V<ll>> a(n, V<ll>(n, -1));
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        if (a[u][v] == -1 || c < a[u][v]) a[u][v] = c;
    }
    cout << pow(a, k)[0][n-1] << "\n";
    return 0;
}
