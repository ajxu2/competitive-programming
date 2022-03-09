// created: 03-07-2022 Mon 10:55 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 1; 
    if (a[0] == 1) {
        for (int i = 0; i < n && ans >= a[i]; i++) ans += a[i];
    }
    cout << ans << "\n";
    return 0;
}
