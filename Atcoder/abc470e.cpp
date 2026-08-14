// created: 08-08-2026 Sat 08:30 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l; cin >> n >> l;
    double avg = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        avg += x;
    }
    avg /= n;
    V<V<V<double>>> dp(n + 1, V<V<double>>(n + 1, V<double>(l + 1, 0))); // dp[cards / 2][seen][lives] = ev from that state
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= l; k++) {
            dp[i][i][k] = dp[i - 1][i - 1][k] + 1;
        }
        for (int j = i - 1; j >= 0; j--) {
            double p1 = (double)j / (2 * i - j); // probability first card matches
            double p2 = 1. / (2 * i - j - 1); // probability second card matches exactly first card
            double p3 = (double)j / (2 * i - j - 1); // probability second card matches, but not with first card
            for (int k = 1; k <= l; k++) {
                if (j > 0)
                    dp[i][j][k] += p1 * (dp[i - 1][j - 1][k] + 1);
                dp[i][j][k] += (1 - p1) * p2 * (dp[i - 1][j][k] + 1);
                dp[i][j][k] += (1 - p1) * p3 * (dp[i - 1][j][k - 1] + (k > 1));
                if (j < i - 1)
                    dp[i][j][k] += (1 - p1) * (1 - p2 - p3) * dp[i][j + 2][k - 1];
            }
        }
    }
    cout << fixed << setprecision(10) << dp[n][0][l] * avg << '\n';
    return 0;
}
