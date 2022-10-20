// created: 10-20-2022 Thu 12:20 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n; int k; cin >> n >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < (1<<k); i++) {
        // PIE!!
        int cnt = 0;
        ll cur = 1;
        bool ok = true;
        for (int j = 0; j < k; j++) {
            if (i&(1<<j)) {
                // check no overflow
                if (LLONG_MAX/a[j] < cur) {
                    ok = false;
                    break;
                }
                cur *= a[j];
                cnt++;
            }
        }
        if (!ok) continue;
        if (cnt & 1) ans += n/cur;
        else ans -= n/cur;
    }
    cout << ans << "\n";
    return 0;
}
