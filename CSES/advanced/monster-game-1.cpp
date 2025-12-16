// created: 12-15-2025 Mon 08:10 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;
struct Line {
    ll a, b;
    ll operator()(ll x) { return a * x + b; }
};

ll isect_x(Line l1, Line l2) { // assume l1.a != l2.a
    if (l1.a < l2.a)
        swap(l1, l2);
    if (l1.b > l2.b)
        return -1;
    return (l2.b - l1.b) / (l1.a - l2.a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    V<int> s(n), f(n);
    for (int& i : s)
        cin >> i;
    for (int& i : f)
        cin >> i;
    deque<pair<ll, Line>> hull; // (start idx, line)
    hull.push_front({0, {x, 0}});
    V<ll> dp(n);
    for (int i = 0; i < n; i++) {
        pair<ll, Line> cur;
        while (!hull.empty() && hull.front().first <= s[i]) {
            cur = hull.front();
            hull.pop_front();
        }
        hull.push_front(cur);
        dp[i] = cur.second(s[i]);
        Line l{f[i], dp[i]};
        while (!hull.empty() && l(hull.back().first) <= hull.back().second(hull.back().first))
            hull.pop_back();
        if (hull.back().second.a != l.a)
            hull.push_back({isect_x(hull.back().second, l) + 1, l});
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
