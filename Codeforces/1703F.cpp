#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < i+1) b.push_back(i+1);
    }
    long long ans = 0;
    for (int i = 0; i < b.size(); i++) {
        int search = a[b[i]-1];
        ans += (lower_bound(b.begin(), b.end(), search) - b.begin());
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
