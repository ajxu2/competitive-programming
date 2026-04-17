// created: 01-22-2026 Thu 12:01 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
        if (i >= 2)
            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
