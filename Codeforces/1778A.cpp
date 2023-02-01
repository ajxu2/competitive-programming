// created: 02-01-2023 Wed 08:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    int tot = accumulate(a.begin(), a.end(), 0);
    bool hasneg = (a[0] < 0), hascons = false;
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i] && a[i] < 0) hascons = true;
        if (a[i] < 0) hasneg = true;
    }
    if (hascons) cout << tot+4 << "\n";
    else if (hasneg) cout << tot << "\n";
    else cout << tot-4 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
