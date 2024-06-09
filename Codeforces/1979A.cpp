// created: 06-08-2024 Sat 10:20 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n-1; i++) ans = min(ans, max(a[i], a[i+1]));
    cout << ~-ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
