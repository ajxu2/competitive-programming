// created: 04-23-2021 Fri 10:00 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    /*
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> a(n);
    vector<vector<int>> ans(m);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i].insert(temp);
    }
    for (int i = 0; i < m; i++) {

    }
    */
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a;
    vector<multiset<int>> available(n);
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            a.push_back({temp, i});
            available[i].insert(temp);
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        ans[a[i][1]][i] = a[i][0];
        available[a[i][1]].erase(available[a[i][1]].find(a[i][0]));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 0) {
                ans[i][j] = *(available[i].begin());
                available[i].erase(available[i].begin());
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m-1];
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
