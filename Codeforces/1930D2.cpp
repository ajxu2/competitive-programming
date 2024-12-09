// created: 12-02-2024 Mon 11:49 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    // f is the number of tiles of length 3 that cover all the ones
    V<ll> dp(n+3, 0); // dp[i] stores sum of all substrings starting at i
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '1') {
            dp[i] = n - i + dp[i+3];
        } else {
            dp[i] = dp[i+1];
        }
    }
    ll ans = accumulate(begin(dp), end(dp), 0LL);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
