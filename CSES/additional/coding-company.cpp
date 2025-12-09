// created: 12-08-2025 Mon 06:00 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

const int MAXSUM = 5000;
const int MAXSZ = 2 * MAXSUM + 1;
int shift(int x) { return x + MAXSUM; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    V<int> t(n);
    for (int& i : t)
        cin >> i;
    sort(begin(t), end(t));
    V<V<ll>> dp(n + 1, V<ll>(MAXSZ, 0)), prev_dp(n + 1, V<ll>(MAXSZ, 0));
    // dp[i][j] = number of ways to have i open teams and sum j
    auto in_bounds = [n](int i, int j) {
        return 0 <= i && i <= n && 0 <= j && j < MAXSZ;
    };
    dp[0][shift(0)] = 1;
    for (int i : t) {
        swap(prev_dp, dp);
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < MAXSZ; k++) {
                // continue team or make singleton team
                dp[j][k] = (j + 1) * prev_dp[j][k];
                // start team
                if (in_bounds(j - 1, k + i))
                    dp[j][k] += prev_dp[j - 1][k + i];
                // end team
                if (in_bounds(j + 1, k - i))
                    dp[j][k] += (j + 1) * prev_dp[j + 1][k - i];
                dp[j][k] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= shift(x); i++)
        ans += dp[0][i];
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
