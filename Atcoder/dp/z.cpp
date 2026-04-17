// created: 04-16-2026 Thu 10:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

struct Line {
    ll a, b;
    ll operator()(ll x) { return a * x + b; }
};

ll isect_x(Line l1, Line l2) {
    return (l2.b - l1.b) / (l1.a - l2.a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll c; cin >> n >> c;
    V<ll> h(n);
    for (ll& i : h)
        cin >> i;
    // dp[i] = min cost to reach stone i
    // dp[i] = min_j (dp[j] + hj^2 - 2hjhi + hi^2 + C)
    // bring out hi^2 + C, and -2hjhi + hj^2 + dp[j] is a line
    V<ll> dp(n, 0);
    deque<pair<ll, Line>> hull; // start, line
    hull.push_front({0, {-2 * h[0], h[0] * h[0]}});
    for (int i = 1; i < n; i++) {
        pair<ll, Line> lst;
        while (!hull.empty() && h[i] >= hull.front().first) {
            lst = hull.front();
            hull.pop_front();
        }
        hull.push_front(lst);
        dp[i] = lst.second(h[i]) + h[i] * h[i] + c;
        Line l = {-2 * h[i], h[i] * h[i] + dp[i]};
        while (!hull.empty() && l(hull.back().first) <= hull.back().second(hull.back().first))
            hull.pop_back();
        ll x = hull.empty() ? h[i] : isect_x(l, hull.back().second) + 1;
        hull.push_back({x, l});
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
