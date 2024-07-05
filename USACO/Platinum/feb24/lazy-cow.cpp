// created: 07-02-2024 Tue 08:58 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

using Point = array<ll, 2>;
Point operator-(const Point& a, const Point& b) { return {a[0] - b[0], a[1] - b[1]}; }
ll cross(const Point& a, const Point& b) { return a[0] * b[1] - a[1] * b[0]; }
ll cross(const Point& a, const Point& b, const Point& c) { return cross(b - a, c - a); }

const int MOD = 1'000'000'007;

ll cost(ll b) {
    if (b == 0) return 0;
    b--;
    ll a = 3, res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return res;
}

ll cost(ll dx, ll dy) {
    ll q = dy / dx, r = dy % dx;
    ll res = 0;
    res += r * cost(q + 1); res %= MOD;
    res += (dx - r) * cost(q); res %= MOD;
    return res;
}

ll cost(const Point& a, const Point& b) { return cost(b[0] - a[0], b[1] - a[1]); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int D; cin >> D;
    set<pair<Point, int>> hull; hull.insert({{0, 0}, -1});
    V<ll> costs(D, 0);
    ll ans = 0;
    for (int i = 0; i < D; i++) {
        Point cur; cin >> cur[0] >> cur[1];
        pair<Point, int> search = {cur, i};
        auto rit = hull.lower_bound(search), lit = prev(rit);
        set<pair<Point, int>>::iterator it;
        if (rit == end(hull) && cur[1] <= lit->first[1]) goto bruh;
        if (rit != end(hull) && cross(cur, lit->first, rit->first) <= 0) goto bruh;
        it = hull.insert(search).first;
        lit = prev(it);
        while (lit != begin(hull) && cross(lit->first, prev(lit)->first, cur) <= 0) {
            ans -= costs[lit->second]; ans %= MOD;
            lit = prev(hull.erase(lit));
        }
        rit = next(hull.find(search));
        while (rit != end(hull) && rit != prev(end(hull)) && cross(rit->first, cur, next(rit)->first) <= 0) {
            ans -= costs[rit->second]; ans %= MOD;
            rit = hull.erase(rit);
        }
        if (rit == prev(end(hull)) && rit->first[1] <= cur[1]) {
            ans -= costs[rit->second]; ans %= MOD;
            rit = hull.erase(rit);
        }
        lit = prev(hull.find(search));
        costs[i] = cost(lit->first, cur);
        ans += costs[i]; ans %= MOD;
        if (rit != end(hull)) {
            ans -= costs[rit->second]; ans %= MOD;
            costs[rit->second] = cost(cur, rit->first);
            ans += costs[rit->second]; ans %= MOD;
        }
        bruh:;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
    return 0;
}
