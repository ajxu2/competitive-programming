// created: 08-10-2021 Tue 05:28 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, r = 0, sum = 0;
    for (int l = 0; l < n; l++) {
        while (r < n) {
            sum += a[r];
            r++;
            if (sum > t) {
                r--;
                sum -= a[r];
                break;
            }
        }
        ans = max(ans, r - l);
        sum -= a[l];
    }
    cout << ans << "\n";
    return 0;
}
