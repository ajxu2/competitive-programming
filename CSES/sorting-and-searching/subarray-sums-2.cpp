// created: 08-05-2022 Fri 08:59 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    map<ll, int> m; m[0] = 1;
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        ans += m[sum - x];
        m[sum]++;
    }
    cout << ans << "\n";
    return 0;
}
