// created: 04-20-2021 Tue 10:11 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<long long> p(n+1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i-1];
    }
    vector<long long> pmin(n+1);
    pmin[0] = 0;
    for (int i = 1; i <= n; i++) {
        pmin[i] = min(pmin[i-1], p[i-1]);
    }
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, p[i] - pmin[i]);
    }
    cout << ans << "\n";
    return 0;
}
