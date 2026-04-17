// created: 01-22-2026 Thu 02:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<bool>> a(n, V<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            short x; cin >> x;
            a[i][j] = x == 1;
        }
    }
    V<int> dp(1 << n, 0);
    dp[0] = 1;
    for (unsigned i = 1; i < (1U << n); i++) {
        int cnt = popcount(i);
        for (int j = 0; j < n; j++)
            if (((i >> j) & 1) && a[j][cnt - 1])
                (dp[i] += dp[i ^ (1 << j)]) %= MOD;
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
