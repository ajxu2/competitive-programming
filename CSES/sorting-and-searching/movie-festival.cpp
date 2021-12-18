// created: 12-17-2021 Fri 10:09 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0];
    }
    sort(a.begin(), a.end());
    int currEnd = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (currEnd <= a[i][1]) {
            currEnd = a[i][0];
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
