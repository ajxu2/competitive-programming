// created: 06-27-2026 Sat 09:31 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    V<int> cost(n), reward(n - 1);
    for (int& i : cost)
        cin >> i;
    for (int& i : reward)
        cin >> i;
    V<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        ll val_rs = reward[i - 2];
        if (s[i - 1] != 'S')
            val_rs -= cost[i - 1];
        if (s[i - 2] != 'R')
            val_rs -= cost[i - 2];
        dp[i] = max(dp[i - 1], dp[i - 2] + val_rs);
    }
    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
