// created: 11-25-2022 Fri 10:51 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> mod(n, 0);
    mod[0]++; // empty prefix
    int sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + a[i]) % n;
        if (sum < 0) sum += n;
        ans += mod[sum];
        mod[sum]++;
    }
    cout << ans << "\n";
    return 0;
}
