// created: 05-25-2022 Wed 12:40 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            ans++; i++;
        }
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
