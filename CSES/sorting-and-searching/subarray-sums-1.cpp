// created: 08-05-2022 Fri 09:20 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int r = 0, ans = 0;
    ll sum = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && sum < x) {
            sum += a[r]; r++;
        }
        if (sum == x) ans++;
        sum -= a[l];
    }
    cout << ans << "\n";
    return 0;
}
