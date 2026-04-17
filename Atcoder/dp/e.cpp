// created: 01-22-2026 Thu 01:00 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    V<int> w(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    int maxv = accumulate(begin(v), end(v), 0);
    V<ll> dp(maxv + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = maxv; j >= v[i]; j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= maxv; i++)
        if (dp[i] <= t)
            ans = i;
    cout << ans << '\n';
    return 0;
}
