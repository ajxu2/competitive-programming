// created: 01-22-2026 Thu 02:00 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<V<ll>> dp(n, V<ll>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = a[i];
        for (int j = i + 1; j < n; j++)
            dp[i][j] = max(-dp[i + 1][j] + a[i], -dp[i][j - 1] + a[j]);
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
