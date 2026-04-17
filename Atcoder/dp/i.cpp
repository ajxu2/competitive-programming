// created: 01-22-2026 Thu 01:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<double> p(n);
    for (double& i : p)
        cin >> i;
    V<double> dp(n + 1, 0);
    dp[0] = 1;
    for (double i : p) {
        for (int j = n; j >= 1; j--)
            dp[j] = i * dp[j - 1] + (1 - i) * dp[j];
        dp[0] *= 1 - i;
    }
    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
        ans += dp[i];
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}
