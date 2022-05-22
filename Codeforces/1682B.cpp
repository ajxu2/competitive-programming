// created: 05-22-2022 Sun 10:31 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = -1;
    for (int i = 0; i < n; i++) if (a[i] != i) ans &= a[i];
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
