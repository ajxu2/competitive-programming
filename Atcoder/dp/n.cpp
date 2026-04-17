// created: 01-22-2026 Thu 02:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<V<ll>> dp(n, V<ll>(n, INF));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 0;
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            for (int k = i; k <= j; k++)
                dp[i][j] += a[k];
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
