// created: 05-23-2022 Mon 02:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    while (n--) {
        ll a, b; cin >> a >> b;
        ll ans = 1;
        while (b != 0) {
            if (b % 2 == 0) {
                b /= 2;
                a *= a;
                a %= MOD;
            } else {
                ans *= a;
                ans %= MOD;
                b--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
