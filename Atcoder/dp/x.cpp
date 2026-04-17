// created: 04-15-2026 Wed 11:34 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MAXS = 10000;
const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<int, 3>> a(n);
    for (auto& [w, s, v] : a)
        cin >> w >> s >> v;
    // idea: if blocks can be stacked, then they can be stacked sorted by w + s
    sort(begin(a), end(a), [](const array<int, 3>& b, const array<int, 3>& c) {
        return b[0] + b[1] < c[0] + c[1];
    });
    V<ll> dp(2 * MAXS + 1, -INF); // dp[i] = max value with sum of weights i
    dp[0] = 0;
    for (auto [w, s, v] : a)
        for (int i = s; i >= 0; i--)
            dp[i + w] = max(dp[i + w], dp[i] + v);
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}
