// created: 01-22-2026 Thu 01:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int n = ssize(s), m = ssize(t);
    V<V<int>> dp(n + 1, V<int>(m + 1, 0));
    V<V<array<int, 2>>> pre(n + 1, V<array<int, 2>>(m + 1, {-1, -1}));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                pre[i][j] = {i - 1, j - 1};
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    pre[i][j] = {i - 1, j};
                } else {
                    dp[i][j] = dp[i][j - 1];
                    pre[i][j] = {i, j - 1};
                }
            }
        }
    }
    string ans;
    int curx = n, cury = m;
    while (curx > 0 && cury > 0) {
        auto [nx, ny] = pre[curx][cury];
        if (nx < curx && ny < cury)
            ans.push_back(s[curx - 1]);
        curx = nx, cury = ny;
    }
    reverse(begin(ans), end(ans));
    cout << ans << '\n';
    return 0;
}
