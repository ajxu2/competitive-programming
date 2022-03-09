// created: 03-07-2022 Mon 10:29 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int optimal = a[n/2];
    for (int i = 0; i < n; i++) a[i] -= optimal;
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) cost -= a[i];
        else cost += a[i];
    }
    cout << cost << "\n";
    return 0;
}
