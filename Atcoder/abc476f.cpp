// created: 09-19-2026 Sat 08:49 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<ll> a(n), b(n);
    for (ll& i : a)
        cin >> i;
    for (ll& i : b)
        cin >> i;
    // grid
    V<V<ll>> p(3 * n, V<ll>(3 * n, 0));
    for (int i = n; i < 2 * n; i++)
        for (int j = n; j < 2 * n; j++)
            p[i][j] = a[i - n] * b[j - n] % m;
    // prefix sums
    for (int i = 1; i < 3 * n; i++)
        for (int j = 1; j < 3 * n; j++)
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    // do some cancer computation then it reduces to sum of prefix sums
    // along diag - along antidiag or something idk
    V<V<ll>> diag(3 * n, V<ll>(3 * n, 0)), antidiag = diag;
    auto calc_cell_naive = [&](int x, int y) -> void {
        for (int i = -n; i < n; i++)
            diag[x][y] += p[x + i][y + i];
        for (int i = -n; i < n; i++)
            antidiag[x][y] += p[x + i][y - i - 1];
    };
    for (int i = n; i < 2 * n; i++) {
        for (int j = n; j < 2 * n; j++) {
            if (i == n || i == 2 * n - 1 || j == n || j == 2 * n - 1) {
                calc_cell_naive(i, j);
            } else {
                diag[i][j] = diag[i - 1][j - 1] + p[i + n - 1][j + n - 1] - p[i - n - 1][j - n - 1];
                antidiag[i][j] = antidiag[i - 1][j + 1] + p[i + n - 1][j - n - 1] - p[i - n - 1][j + n - 1];
            }
        }
    }
    ll ans = 0;
    for (int i = n; i < 2 * n; i++) {
        for (int j = n ; j < 2 * n; j++) {
            ll f = n * p[3 * n - 1][3 * n - 1] - diag[i][j] + antidiag[i][j];
            ans ^= f + (i - n) * n + (j - n);
        }
    }
    cout << ans << '\n';
    return 0;
}
