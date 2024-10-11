// created: 09-30-2024 Mon 01:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll c2(int x) { return (ll)x * (x - 1) >> 1; }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    V<int> freq(n+1, 0);
    for (int& i : a) {
        cin >> i;
        freq[i]++;
    }
    V<bool> is_multiple(n+1, false);
    for (int i = 1; i <= n; i++) if (freq[i] != 0) is_multiple[i] = true;
    for (int i = 1; i <= n; i++) {
        if (!is_multiple[i]) continue;
        for (int j = 2 * i; j <= n; j += i) is_multiple[j] = true;
    }
    V<ll> dp(n+1, 0);
    for (int i = n; i >= 1; i--) {
        int whar = 0;
        for (int j = i; j <= n; j += i) whar += freq[j];
        dp[i] = c2(whar);
        for (int j = 2 * i; j <= n; j += i) dp[i] -= dp[j];
    }
    ll ans = c2(n);
    for (int i = 1; i <= n; i++) if (is_multiple[i]) ans -= dp[i];
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
