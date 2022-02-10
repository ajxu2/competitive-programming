// created: 01-31-2021 Mon 10:37 AM

#include <bits/stdc++.h>
using namespace std;

int TC, n, a[200000];
const int MOD = 1e9+7;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // get minimum element
    sort(a, a+n);
    int m = a[0];
    // get the and of all elements in the array
    int tmp = a[0];
    for (int i = 1; i < n; i++) tmp &= a[i];
    if (tmp != m) {
        // cannot be good
        cout << "0\n";
        return;
    }
    // otherwise, get the number of minimum elements in the array
    // these will go at the front and back
    int cnt = 0;
    while (cnt < n && a[cnt] == m) cnt++;
    // cnt*(cnt-1)*(n-2)!
    long long ans = 1;
    for (int i = 1; i <= n-2; i++) {
        ans *= i; ans %= MOD;
    }
    ans *= cnt; ans %= MOD;
    ans *= (cnt-1); ans %= MOD;
    cout << ans << "\n";
}

int main() {
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
