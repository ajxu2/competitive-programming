#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') a[i][j] = false;
            else a[i][j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = 0;
            if (a[i][j]) num++;
            if (a[j][n-i-1]) num++;
            if (a[n-i-1][n-j-1]) num++;
            if (a[n-j-1][i]) num++;
            if (num <= 2) {
                ans += num;
                a[i][j] = false; a[j][n-i-1] = false; a[n-i-1][n-j-1] = false; a[n-j-1][i] = false;
            }
            else {
                ans += (4-num);
                a[i][j] = true; a[j][n-i-1] = true; a[n-i-1][n-j-1] = true; a[n-j-1][i] = true;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
