// created: 09-03-2022 Sat 11:47 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[2005][2005][2]; // dp[i][j][k] = first i of bessie, first j of elsie, who the last character belongs to

const int MOD = 1000000007;

string rm(string s) {
    // simplify the expression
    // remove everything before last 0, and remove any 1s
    string res;
    for (char i : s) {
        if (i == '0') res = "0";
        else if (i != '1') res.push_back(i);
    }
    return res;
}

void solve() {
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    s1 = rm(s1); s2 = rm(s2);
    for (int i = 0; i <= s1.length(); i++) {
        dp[i][0][0] = 1; dp[i][0][1] = 0;
    }
    for (int j = 0; j <= s2.length(); j++) {
        dp[0][j][0] = 0; dp[0][j][1] = 1;
    }
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            // dp[i][j][0]
            dp[i][j][0] = dp[i-1][j][0];
            if ((s1[i-1] == '+') ^ (s2[j-1] == '+')) {
                // not of same type, ok to add
                dp[i][j][0] += dp[i-1][j][1]; dp[i][j][0] %= MOD;
            }
            // dp[i][j][1]
            dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
        }
    }
    cout << (dp[s1.length()][s2.length()][0] + dp[s1.length()][s2.length()][1]) % MOD << "\n";
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
