// created: 09-24-2023 Sun 09:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<array<int, 2>> a(n);
    for (array<int, 2>& i : a) cin >> i[0] >> i[1];
    for (int i = 1; i < n; i++) {
        if (a[i][0] >= a[0][0] && a[i][1] >= a[0][1]) {
            cout << "-1\n";
            return;
        }
    }
    cout << a[0][0] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
