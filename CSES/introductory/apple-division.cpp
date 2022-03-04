// created: 03-03-2022 Thu 09:25 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n); long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // bitmasky
    long long ans = 1e18;
    for (int i = 0; i < (1<<n); i++) {
        long long thisSum = 0;
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) thisSum += a[j];
        }
        if (2*thisSum < sum) ans = min(ans, sum - 2*thisSum);
        else ans = min(ans, 2*thisSum - sum);
    }
    cout << ans << "\n";
    return 0;
}
