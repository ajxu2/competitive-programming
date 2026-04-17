// created: 01-23-2026 Fri 04:38 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<int>> a(n, V<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    V<ll> cost(1 << n, 0);
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (((i >> j) & 1) && ((i >> k) & 1))
                    cost[i] += a[j][k];
    V<ll> dp(1 << n, 0);
    for (int i = 1; i < (1 << n); i++)
        for (int j = i; j > 0; j = (j - 1) & i)
            dp[i] = max(dp[i], dp[i ^ j] + cost[j]);
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
