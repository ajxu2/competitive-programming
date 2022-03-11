// created: 03-10-2022 Thu 11:19 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef LOCAL
    ifstream cin("berries.in");
    ofstream cout("berries.out");
#endif
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, maxb = *max_element(a.begin(), a.end());
    for (int i = 1; i <= maxb; i++) {
        // i represents the amount of berries in a basket to start
        vector<int> b = a;
        vector<int> baskets(k);
        int basketsUsed = 0;
        for (int j = 0; j < n; j++) basketsUsed += a[j]/i;
        if (basketsUsed < k/2) break;
        if (basketsUsed >= k) {
            ans = max(ans, k/2*i);
            continue;
        }
        sort(a.begin(), a.end(), [=](const int& x, const int& y) { return x%i > y%i; });
        int thisAns = (basketsUsed - k/2)*i;
        for (int j = 0; j < n && j < k - basketsUsed; j++) thisAns += a[j]%i;
        ans = max(thisAns, ans);
    }
    cout << ans << "\n";
    return 0;
}
