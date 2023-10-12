// created: 10-09-2023 Mon 09:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    if (n % 3 != 0) {
        if (n <= 5) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << "1 2 " << n-3 << "\n";
    } else {
        if (n <= 9) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << "1 4 " << n-5 << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
