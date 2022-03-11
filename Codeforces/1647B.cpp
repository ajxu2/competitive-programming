// created: 03-11-2022 Fri 08:42 AM

#include <bits/stdc++.h>
using namespace std;

const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') a[i][j] = true;
        }
    }
    bool works = true;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            int cnt1 = 0;
            if (a[i][j]) cnt1++;
            if (a[i+1][j]) cnt1++;
            if (a[i][j+1]) cnt1++;
            if (a[i+1][j+1]) cnt1++;
            if (cnt1 == 3) works = false;
        }
    }
    if (works) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
