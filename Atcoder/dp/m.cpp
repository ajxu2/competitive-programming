// created: 01-22-2026 Thu 02:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<int> dp(k + 1, 0);
    dp[0] = 1;
    V<ll> p(k + 1, 1);
    for (int i : a) {
        for (int j = 0; j <= k; j++) {
            int l = j - i;
            if (l <= 0)
                dp[j] = p[j];
            else
                dp[j] = (p[j] - p[l - 1]) % MOD;
        }
        p[0] = dp[0];
        for (int j = 1; j <= k; j++)
            p[j] = (p[j - 1] + dp[j]) % MOD;
    }
    int ans = dp[k];
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';
    return 0;
}
