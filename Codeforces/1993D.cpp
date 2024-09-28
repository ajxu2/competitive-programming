// created: 07-09-2024 Tue 01:16 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a) cin >> i;
    int final_len = (n - 1) % k + 1;
    // indices mod k are 0, 1, ..., final_len - 1
    auto i_dont_know_what_this_does = [&](int x) -> bool {
        // check if we can get median >= x
        V<int> dp(final_len, 0);
        for (int i = 0; i < n; i++) {
            if (i % k >= final_len) continue;
            if (i % k == 0) dp[0] = max(dp[0], a[i] >= x ? 1 : 0);
            else dp[i % k] = max(dp[i % k], dp[i % k - 1] + (a[i] >= x ? 1 : 0));
        }
        return dp.back() >= final_len / 2 + 1;
    };
    int l = 0, r = 1e9 + 7;
    while (l < r) {
        int mid = midpoint(l, r + 1);
        if (i_dont_know_what_this_does(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
