// created: 01-15-2026 Thu 03:06 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, w; cin >> n >> w;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<ll> sum(2 * w);
    for (int i = 0; i < n; i++)
        sum[i % (2 * w)] += a[i];
    ll cur = 0;
    for (int i = 0; i < w; i++)
        cur += sum[i];
    ll ans = cur;
    for (int i = 0; i < 2 * w - 1; i++) {
        cur += sum[(i + w) % (2 * w)];
        cur -= sum[i];
        ans = min(ans, cur);
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
