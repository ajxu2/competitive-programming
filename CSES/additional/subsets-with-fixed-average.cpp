// created: 12-25-2025 Thu 03:25 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;
const int MAX = 500 * 500;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a; cin >> n >> a;
    // idea: subtract a from everything, then becomes sum zero
    V<int> x(n);
    for (int& i : x) {
        cin >> i;
        i -= a;
    }
    V<int> dp(2 * MAX + 1, 0), old_dp; // dp[x] = ways to get sum = x - MAX
    dp[MAX] = 1;
    for (int i : x) {
        old_dp = dp;
        for (int j = 0; j <= 2 * MAX; j++)
            if (0 <= j - i && j - i <= 2 * MAX)
                (dp[j] += old_dp[j - i]) %= MOD;
    }
    cout << (dp[MAX] + MOD - 1) % MOD << '\n';
    return 0;
}
