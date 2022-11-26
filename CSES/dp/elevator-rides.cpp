// created: 11-25-2022 Fri 10:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> dp1(1<<n, 1e9), dp2(1<<n, 1e9); // dp1 = answer for set, dp2 = minimum weight of last ride
    dp1[0] = 1; dp2[0] = 0;
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                // should this person be in last group?
                int ex = i^(1<<j);
                int rides, weight;
                if (dp2[ex] + a[j] > x) {
                    rides = dp1[ex] + 1;
                    weight = a[j];
                } else {
                    rides = dp1[ex];
                    weight = dp2[ex] + a[j];
                }
                if (rides == dp1[i]) dp2[i] = min(dp2[i], weight);
                else if (rides < dp1[i]) {
                    dp1[i] = rides;
                    dp2[i] = weight;
                }
            }
        }
    }
    cout << dp1.back() << "\n";
    return 0;
}
