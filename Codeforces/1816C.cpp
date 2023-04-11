// created: 04-09-2023 Sun 10:26 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    // proof by AC awesome sauce
    if (n % 2 == 1) cout << "YES\n";
    else {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) sum += a[n-1-i];
            else sum -= a[n-1-i];
        }
        if (sum >= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
