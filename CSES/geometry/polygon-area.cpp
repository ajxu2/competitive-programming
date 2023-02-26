// created: 02-25-2023 Sat 05:13 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<ll, 2>> a(n);
    for (array<ll, 2>& i : a) cin >> i[0] >> i[1];
    // shoelace :yayy:
    a.push_back(a.front());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i][0] * a[i+1][1];
        ans -= a[i][1] * a[i+1][0];
    }
    if (ans < 0) ans = -ans;
    cout << ans << "\n";
    return 0;
}
