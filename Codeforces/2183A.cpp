// created: 01-07-2026 Wed 08:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    cout << (a[0] == 0 && a[n - 1] == 0 ? "Bob" : "Alice") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
