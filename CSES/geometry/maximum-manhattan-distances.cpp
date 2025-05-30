// created: 05-29-2025 Thu 03:08 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = (ll)1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    // rotate everything by 45 deg then becomes chebyshev distance
    ll minx = INF, maxx = -INF, miny = INF, maxy = -INF;
    for (int i = 0; i < n; i++) {
        ll x1, y1; cin >> x1 >> y1;
        ll x = x1 - y1, y = x1 + y1;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
        cout << max(maxx - minx, maxy - miny) << '\n';
    }
    return 0;
}
