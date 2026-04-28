// created: 04-25-2026 Sat 08:50 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    map<int, ll> sums;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sums[x] += x;
    }
    V<ll> b;
    for (auto [_, s] : sums)
        b.push_back(s);
    sort(begin(b), end(b));
    ll ans = 0;
    for (int i = 0; i < ssize(b) - k; i++)
        ans += b[i];
    cout << ans << '\n';
    return 0;
}
