// created: 06-29-2023 Thu 02:46 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

array<int, 2> operator+(array<int, 2> a, array<int, 2> b) { return {a[0] + b[0], a[1] + b[1]}; }
void ckmax(array<int, 2>& a, array<int, 2> b) {
    if (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1])) a = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.length();
    V<int> c(n);
    for (int& i : c) cin >> i;
    string b = "bessie";
    V<array<array<int, 2>, 6>> dp(n); // :skull: dp[i][j] = ans for s[0..i], jth char of bessie
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            dp[i][j] = {-1000, 1000000000};
        }
    }
    if (s[0] == b[0]) dp[0][0] = {0, 0};
    dp[0][5] = {0, 0};
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            // don't remove this letter
            if (s[i] == b[j]) dp[i][j] = dp[i-1][(j+5)%6];
            // remove this letter
            ckmax(dp[i][j], dp[i-1][j] + array<int, 2>{0, c[i]});
        }
        if (s[i] == b[5]) dp[i][5] = dp[i-1][4] + array<int, 2>{1, 0};
        for (int j = 0; j < 6; j++) ckmax(dp[i][5], dp[i-1][j]);
    }
    array<int, 2> ans = {0, 1000000000};
    for (int i = 0; i < 6; i++) ckmax(ans, dp[n-1][i]);
    cout << ans[0] << "\n" << ans[1] << "\n";
    return 0;
}
