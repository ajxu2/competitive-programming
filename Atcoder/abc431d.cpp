// created: 11-08-2025 Sat 07:10 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;
const int MXSUM = 500 * 500;
const int LEN = 2 * MXSUM + 1;
constexpr int shift(int x) {
    return x + MXSUM;
}

void chmax(ll& x, ll y) {
    if (y > x)
        x = y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> w(n), h(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> h[i] >> b[i];
    V<ll> dp(LEN, -INF);
    dp[shift(w[0])] = h[0];
    dp[shift(-w[0])] = b[0];
    dp[shift(0)] = 0;
    for (int i = 1; i < n; i++) {
        V<ll> DP = dp;
        for (int j = -MXSUM; j <= MXSUM; j++) {
            if (dp[shift(j)] != -INF) {
                chmax(DP[shift(j+w[i])], dp[shift(j)] + h[i]);
                chmax(DP[shift(j-w[i])], dp[shift(j)] + b[i]);
            }
        }
        dp = DP;
    }
    ll ans = -INF;
    for (int i = -MXSUM; i <= 0; i++)
        chmax(ans, dp[shift(i)]);
    cout << ans << '\n';
    return 0;
}
