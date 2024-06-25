// created: 06-25-2024 Tue 09:32 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a > b) {
        swap(a, b); swap(c, d);
    }
    if (d <= c) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
