// created: 12-20-2021 Mon 11:53 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    multiset<int> peaks;
    peaks.insert(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] >= *prev(peaks.end())) {
            // no tower's peak is big enough
            // start a new tower
            peaks.insert(a[i]);
            ans++;
        } else {
            // add to an existing tower
            // find smallest peak such that the next block still fits
            auto it = peaks.upper_bound(a[i]);
            peaks.erase(it);
            peaks.insert(a[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
