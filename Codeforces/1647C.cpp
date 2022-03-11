// created: 03-11-2022 Fri 09:48 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') a[i][j] = true;
        }
    }
    if (a[0][0]) {
        cout << "-1\n";
        return;
    }
    vector<array<int, 4>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = m-1; j >= 1; j--) {
            if (a[i][j]) ans.push_back({i+1, j, i+1, j+1});
        }
    }
    for (int i = n-1; i >= 1; i--) {
        if (a[i][0]) ans.push_back({i, 1, i+1, 1});
    }
    cout << ans.size() << "\n";
    for (array<int, 4> i : ans) {
        for (int j : i) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
