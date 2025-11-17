// created: 11-15-2025 Sat 04:02 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<V<int>> a(n, V<int>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] - 'A';
    }
    V<V<int>> h_streak(n, V<int>(n));
    V<V<int>> v_streak(n, V<int>(n));
    V<V<int>> dp(n, V<int>(n));
    V<ll> ans(k, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 || a[i][j-1] != a[i][j])
                h_streak[i][j] = 1;
            else
                h_streak[i][j] = h_streak[i][j-1] + 1;
            if (i == 0 || a[i-1][j] != a[i][j])
                v_streak[i][j] = 1;
            else
                v_streak[i][j] = v_streak[i-1][j] + 1;
            if (i == 0 || j == 0 || a[i-1][j-1] != a[i][j])
                dp[i][j] = 1;
            else
                dp[i][j] = min(min(h_streak[i][j], v_streak[i][j]), dp[i-1][j-1] + 1);
            ans[a[i][j]] += dp[i][j];
        }
    }
    for (ll i : ans)
        cout << i << '\n';
    return 0;
}
