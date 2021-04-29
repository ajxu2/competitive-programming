// created: 04-29-2021 Thu 10:17 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>());
    vector<int> u(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        a[u[i]].push_back(s[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i].empty()) {
            sort(a[i].begin(), a[i].end(), greater<int>());
        }
    }
    vector<vector<long long>> p(n+1, vector<long long>());
    vector<long long> ans(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (!a[i].empty()) {
            p[i].push_back(0);
            for (int j = 0; j < a[i].size(); j++) {
                p[i].push_back(p[i][j] + a[i][j]);
            }
            for (int j = 1; j <= a[i].size(); j++) {
                ans[j] += p[i][a[i].size()-(a[i].size()%j)];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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
