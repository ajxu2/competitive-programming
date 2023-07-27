// created: 07-27-2023 Thu 01:26 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n, k; cin >> n >> k;
    V<int> a(n), cold(k), hot(k);
    for (int& i : a) {
        cin >> i; i--;
    }
    for (int& i : cold) cin >> i;
    for (int& i : hot) cin >> i;
    V<V<ll>> dp(n, V<ll>(n, 1e18)); // dp[i][j] = ans for [0..i], last programs j, i
    dp[0][0] = cold[a[0]];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i-1; j++) {
            // transitioned from j, i-1
            dp[i][j] = dp[i-1][j];
            if (a[i] == a[i-1]) dp[i][j] += hot[a[i]];
            else dp[i][j] += cold[a[i]];
        }
        // for dp[i][i-1], could have transitioned from any j, i-1
        for (int j = 0; j < i-1; j++) {
            if (a[i] == a[j]) dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + hot[a[i]]);
            else dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + cold[a[i]]);
        }
        dp[i][i-1] = min(dp[i][i-1], dp[i-1][i-1] + cold[a[i]]);
        if (a[i] == a[i-1]) dp[i][i] = dp[i-1][i-1] + hot[a[i]];
        else dp[i][i] = dp[i-1][i-1] + cold[a[i]];
    }
    cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
