// created: 01-22-2026 Thu 02:41 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

using Matrix = V<V<ll>>;
const int MOD = 1'000'000'007;

Matrix matmul(Matrix A, Matrix B) {
    int n = ssize(A), d = ssize(B), m = ssize(B[0]);
    Matrix res(n, V<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < d; k++)
                (res[i][j] += A[i][k] * B[k][j]) %= MOD;
    return res;
}

Matrix I(int n) {
    Matrix res(n, V<ll>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

Matrix matpow(Matrix A, ll b) {
    Matrix res = I(ssize(A));
    while (b > 0) {
        if (b & 1)
            res = matmul(res, A);
        A = matmul(A, A);
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k; cin >> n >> k;
    Matrix A(n, V<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    Matrix B = matpow(A, k);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += B[i][j];
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
