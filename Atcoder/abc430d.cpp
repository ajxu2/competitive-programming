// created: 11-01-2025 Sat 08:16 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    map<int, int> mp;
    mp[0] = 0;
    V<int> d(n + 1, INF);
    ll ans = INF;
    auto upd = [&](int i, int x) -> void {
        x = min(x, d[i]);
        ans += x - d[i];
        d[i] = x;
    };
    for (int i = 0; i < n; i++) {
        auto it = mp.lower_bound(a[i]);
        int dst = INF;
        if (it != begin(mp)) {
            auto [posl, idxl] = *prev(it);
            upd(idxl, a[i] - posl);
            dst = min(dst, a[i] - posl);
        }
        if (it != end(mp)) {
            auto [posr, idxr] = *it;
            upd(idxr, posr - a[i]);
            dst = min(dst, posr - a[i]);
        }
        mp[a[i]] = i + 1;
        d[i + 1] = dst;
        ans += dst;
        cout << ans << '\n';
    }
    return 0;
}
