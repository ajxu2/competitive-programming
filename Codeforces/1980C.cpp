// created: 06-08-2024 Sat 10:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    int m; cin >> m;
    V<int> d(m);
    for (int& i : d) cin >> i;
    multiset<int> ms(begin(d), end(d));
    for (int i = 0; i < n; i++) if (a[i] != b[i]) {
        auto it = ms.find(b[i]);
        if (it == end(ms)) {
            cout << "NO\n";
            return;
        }
        ms.erase(it);
    }
    if (find(begin(b), end(b), d.back()) == end(b)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
