// created: 05-13-2022 Fri 08:00 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'R') a[i][j] = true;
        }
    }
    int minX = 1e9, minY = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) minY = min(minY, j);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j][i]) minX = min(minX, j);
        }
    }
    if (a[minX][minY]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
