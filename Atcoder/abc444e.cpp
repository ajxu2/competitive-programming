// created: 02-07-2026 Sat 07:08 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    ll ans = 0;
    int r = 0;
    multiset<int> ms;
    for (int l = 0; l < n; l++) {
        while (r < n) {
            auto it = ms.lower_bound(a[r]);
            bool bad = false;
            if (it != end(ms) && *it - a[r] < d)
                bad = true;
            if (it != begin(ms) && a[r] - *prev(it) < d)
                bad = true;
            if (bad)
                break;
            ms.insert(a[r]);
            r++;
        }
        ans += r - l;
        ms.erase(ms.find(a[l]));
    }
    cout << ans << '\n';
    return 0;
}
