// created: 05-25-2022 Wed 06:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }
    cout << dp.size() << "\n";
    return 0;
}
