// created: 06-13-2026 Sat 08:10 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MAXN = 300'005;
const int MAXK = 15;
const int INF = 1'000'000'007;
int dp[MAXN][MAXK];

void solve() {
    string s; cin >> s;
    int k; cin >> k;
    int n = ssize(s);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = j == 0 ? 0 : INF;
    for (int i = 3; i <= n; i++) {
        int edit = (s[i - 3] != 'A') + (s[i - 2] != 'B') + (s[i - 1] != 'C');
        if (edit == 0) {
            for (int j = 0; j <= k; j++)
                dp[i][j] = dp[i - 3][j];
            continue;
        }
        bool broken = (i >= 4 && s.substr(i - 4, 3) == "ABC") || (i >= 5 && s.substr(i - 5, 3) == "ABC");
        if (broken) {
            for (int j = 1; j <= k; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i - 3][j] + edit);
        } else {
            for (int j = 1; j <= k; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i - 3][j - 1] + edit);
        }
    }
    int ans = dp[n][k];
    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
