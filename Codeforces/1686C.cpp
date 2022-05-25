// created: 05-25-2022 Wed 12:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i += 2) ans[i] = a[i/2];
    for (int i = 1; i < n; i += 2) ans[i] = a[i/2+n/2];
    bool works = true;
    for (int i = 0; i < n; i++) {
        if (ans[i] == ans[(i+1)%n]) works = false;
    }
    if (works) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
    } else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
