// created: 05-25-2022 Wed 12:32 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    bool works = false;
    for (int i = 0; i < n; i++) {
        if ((sum-a[i]) % (n-1) == 0 && (sum-a[i]) / (n-1) == a[i]) works = true;
    }
    if (works) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
