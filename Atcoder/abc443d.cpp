// created: 01-31-2026 Sat 12:13 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    // i think i've seen this problem before lol
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int shift = max(0, a[i] - (a[i - 1] + 1));
        ans += shift;
        a[i] -= shift;
    }
    for (int i = n - 2; i >= 0; i--) {
        int shift = max(0, a[i] - (a[i + 1] + 1));
        ans += shift;
        a[i] -= shift;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
