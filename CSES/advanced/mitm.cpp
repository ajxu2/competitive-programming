// created: 03-14-2022 Mon 09:12 AM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> meet, middle;
    // populate meet
    for (int i = 0; i < (1<<(n/2)); i++) {
        long long tmp = 0;
        for (int j = 0; j < n/2; j++) {
            if (i&(1<<j)) tmp += a[j];
        }
        meet.push_back(tmp);
    }
    // populate middle
    for (int i = 0; i < (1<<((n+1)/2)); i++) {
        long long tmp = 0;
        for (int j = 0; j < (n+1)/2; j++) {
            if (i&(1<<j)) tmp += a[n/2+j];
        }
        middle.push_back(tmp);
    }
    sort(meet.begin(), meet.end());
    sort(middle.begin(), middle.end());
    long long ans = 0;
    for (long long i : meet) {
        auto it1 = lower_bound(middle.begin(), middle.end(), x-i);
        auto it2 = upper_bound(middle.begin(), middle.end(), x-i);
        for (; it1 != it2; it1++) ans++;
    }
    cout << ans << "\n";
    return 0;
}
