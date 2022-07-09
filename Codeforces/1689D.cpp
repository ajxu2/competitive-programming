// created: 07-09-2022 Sat 12:47 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    // find max values of:
    // -i-j from top left, -i+j from top right, i-j from bottom left, i+j from bottom right
    int n, m; cin >> n >> m;
    vector<vector<bool>> black(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) if (s[j] == 'B') black[i][j] = true;
    }
    // spaghetti
    vector<vector<int>> dp1(n, vector<int>(m, -1e9)), dp2 = dp1, dp3 = dp1, dp4 = dp1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (black[i][j]) dp1[i][j] = -i-j;
            if (i > 0) dp1[i][j] = max(dp1[i][j], dp1[i-1][j]);
            if (j > 0) dp1[i][j] = max(dp1[i][j], dp1[i][j-1]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = m-1; j >= 0; j--) {
            if (black[i][j]) dp2[i][j] = -i+j;
            if (i > 0) dp2[i][j] = max(dp2[i][j], dp2[i-1][j]);
            if (j < m-1) dp2[i][j] = max(dp2[i][j], dp2[i][j+1]);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (black[i][j]) dp3[i][j] = i-j;
            if (i < n-1) dp3[i][j] = max(dp3[i][j], dp3[i+1][j]);
            if (j > 0) dp3[i][j] = max(dp3[i][j], dp3[i][j-1]);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (black[i][j]) dp4[i][j] = i+j;
            if (i < n-1) dp4[i][j] = max(dp4[i][j], dp4[i+1][j]);
            if (j < m-1) dp4[i][j] = max(dp4[i][j], dp4[i][j+1]);
        }
    }
    int x, y, mn = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int thisans = max(dp1[i][j]+i+j, max(dp2[i][j]+i-j, max(dp3[i][j]-i+j, dp4[i][j]-i-j)));
            if (mn > thisans) {
                mn = thisans; x = i; y = j;
            }
        }
    }
    cout << x+1 << " " << y+1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
