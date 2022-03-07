// created: 03-06-2022 Sun 09:17 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a[tmp] = i;
    }
    vector<int> b(n+1);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        b[tmp] = i;
    }
    vector<array<int, 2>> c;
    for (int i = 1; i <= n; i++) c.push_back({a[i], b[i]});
    sort(c.begin(), c.end());
    int ans = 0, runningMax = 0;
    for (int i = 1; i < n; i++) {
        runningMax = max(runningMax, c[i-1][1]);
        if (runningMax > c[i][1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
