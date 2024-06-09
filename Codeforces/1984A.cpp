// created: 06-09-2024 Sun 09:36 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    if (a[0] == a[n-1]) cout << "NO\n";
    else {
        cout << "YES\n";
        if (a[1] == a[n-1]) {
            cout << "RR";
            for (int i = 0; i < n-2; i++) cout << 'B';
        } else {
            cout << 'R';
            for (int i = 0; i < n-1; i++) cout << 'B';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
