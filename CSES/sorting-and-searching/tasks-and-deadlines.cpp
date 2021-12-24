// created: 12-20-2021 Mon 11:47 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    // always do shortest tasks first
    sort(a.begin(), a.end());
    long long t = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        t += a[i][0];
        ans += (a[i][1] - t);
    }
    cout << ans << "\n";
    return 0;
}
