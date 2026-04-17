// created: 01-22-2026 Thu 01:26 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1)
            cnt1++;
        if (x == 2)
            cnt2++;
        if (x == 3)
            cnt3++;
    }
    V<V<V<double>>> dp(n + 1, V<V<double>>(n + 1, V<double>(n + 1, 0)));
    for (int sum = 1; sum <= n; sum++) {
        for (int i = sum; i >= 0; i--) {
            for (int j = sum - i; j >= 0; j--) {
                int k = sum - i - j;
                dp[i][j][k] = (double)n / sum;
                if (i > 0)
                    dp[i][j][k] += dp[i - 1][j][k] * i / sum;
                if (j > 0)
                    dp[i][j][k] += dp[i + 1][j - 1][k] * j / sum;
                if (k > 0)
                    dp[i][j][k] += dp[i][j + 1][k - 1] * k / sum;
            }
        }
    }
    cout << fixed << setprecision(10) << dp[cnt1][cnt2][cnt3] << '\n';
    return 0;
}
