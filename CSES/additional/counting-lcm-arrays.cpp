// created: 12-22-2025 Mon 10:00 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;
using Matrix = V<V<ll>>;

Matrix matmul(Matrix A, Matrix B) {
    int d1 = ssize(A), d2 = ssize(B), d3 = ssize(B[0]);
    Matrix res(d1, V<ll>(d3, 0));
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d3; j++)
            for (int k = 0; k < d2; k++)
                (res[i][j] += A[i][k] * B[k][j]) %= MOD;
    return res;
}

Matrix fexp(Matrix A, int b) {
    int d = ssize(A);
    Matrix res(d, V<ll>(d, 0));
    for (int i = 0; i < d; i++)
        res[i][i] = 1;
    while (b > 0) {
        if (b & 1)
            res = matmul(res, A);
        A = matmul(A, A);
        b >>= 1;
    }
    return res;
}

void solve() {
    // prime factorize, then lcm becomes max, which is a linear recurrence
    int n, k; cin >> n >> k;
    V<int> exponents;
    for (int i = 2; i * i <= k; i++) {
        int cnt = 0;
        while (k % i == 0) {
            k /= i;
            cnt++;
        }
        if (cnt != 0)
            exponents.push_back(cnt);
    }
    if (k > 1)
        exponents.push_back(1);
    ll ans = 1;
    for (int i : exponents) {
        Matrix A = {{1, (ll)i}, {1, 0}};
        (ans *= fexp(A, n + 1)[0][0]) %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
