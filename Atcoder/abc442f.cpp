// created: 01-24-2026 Sat 07:59 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<string> a(n);
    for (string& i : a)
        cin >> i;
    V<V<int>> dp(n + 1, V<int>(n + 1, 0)); // first i rows, first j chars white
    for (int i = 1; i <= n; i++) {
        V<int> x(n + 1, 0);
        for (int j = 0; j < n; j++)
            x[0] += a[i - 1][j] == '.';
        for (int j = 1; j <= n; j++)
            x[j] = x[j - 1] + (a[i - 1][j - 1] == '.' ? -1 : 1);
        int mn = INF;
        for (int j = n; j >= 0; j--) {
            mn = min(mn, dp[i - 1][j]);
            dp[i][j] = mn + x[j];
        }
    }
    cout << *min_element(begin(dp[n]), end(dp[n])) << '\n';
    return 0;
}
