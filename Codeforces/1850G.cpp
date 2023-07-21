// created: 07-21-2023 Fri 11:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    V<array<ll, 2>> a(n);
    for (array<ll, 2>& i : a) cin >> i[0] >> i[1];
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        sort(a.begin(), a.end());
        int lst = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][0] != a[lst][0]) {
                ll diff = j - lst;
                ans += diff * (diff - 1);
                lst = j;
            }
        }
        ll diff = n - lst;
        ans += diff * (diff - 1);
        for (array<ll, 2>& i : a) {
            array<ll, 2> j = {i[0] - i[1], i[0] + i[1]};
            i = j;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
