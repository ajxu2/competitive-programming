// created: 01-22-2026 Thu 01:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w; cin >> h >> w;
    V<string> a(h);
    for (string& i : a)
        cin >> i;
    V<V<int>> dp(h, V<int>(w, 0));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#')
                continue;
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[h - 1][w - 1] << '\n';
    return 0;
}
