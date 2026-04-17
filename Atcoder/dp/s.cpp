// created: 01-23-2026 Fri 01:16 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string k; int d; cin >> k >> d;
    int n = ssize(k);
    V<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = k[i] - '0';
    V<V<int>> dp(n, V<int>(d, 0));
    for (int i = 0; i < a[0]; i++)
        dp[0][i % d]++;
    int sum = a[0] % d;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int lst = 0; lst < 10; lst++) {
                int prev_sum = (j - lst) % d;
                if (prev_sum < 0)
                    prev_sum += d;
                (dp[i][j] += dp[i - 1][prev_sum]) %= MOD;
            }
        }
        for (int lst = 0; lst < a[i]; lst++)
            (dp[i][(sum + lst) % d] += 1) %= MOD;
        (sum += a[i]) %= d;
    }
    int ans = dp[n - 1][0];
    if (sum != 0)
        (ans += MOD - 1) %= MOD; // subtract zero case
    cout << ans << '\n';
    return 0;
}
