// created: 07-25-2026 Sat 09:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    // connected component dp???
    V<V<ll>> dp(n, V<ll>(n + 1, 0));
    if (s[0] == 'x') {
        cout << "0\n";
        return 0;
    }
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            // between
            (dp[i][j - 1] += (j - 1) * dp[i - 1][j]) %= MOD;
            // on side
            (dp[i][j] += 2 * j * dp[i - 1][j]) %= MOD;
            // new
            (dp[i][j + 1] += (j + 1) * dp[i - 1][j]) %= MOD;
        }
        if (s[i] == 'x') {
            dp[i][1] = 0;
        } else {
            for (int j = 2; j <= i + 1; j++)
                dp[i][j] = 0;
        }
    }
    cout << dp[n - 1][1] << '\n';
    return 0;
}
