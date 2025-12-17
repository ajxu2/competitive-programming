// created: 12-16-2025 Tue 03:09 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
    auto cost = [&p](int l, int r) {
        int sum = p[r] - p[l];
        return (ll)sum * sum;
    };
    V<V<ll>> dp(k + 1, V<ll>(n + 1, 0));
    // dp[k][n] = min cost split [0, n) into k subarrays
    for (int i = 0; i <= n; i++)
        dp[1][i] = cost(0, i);
    for (int i = 2; i <= k; i++) {
        auto compute = [&](auto&& self, int l, int r, int optl, int optr) -> void {
            // inclusive [l, r], [optl, optr]
            if (l > r)
                return;
            int mid = midpoint(l, r);
            int opt = -1;
            ll optval = INF;
            for (int j = optl; j <= min(mid, optr); j++) {
                ll cur = dp[i - 1][j] + cost(j, mid);
                if (cur < optval) {
                    optval = cur;
                    opt = j;
                }
            }
            dp[i][mid] = optval;
            self(self, l, mid - 1, optl, opt);
            self(self, mid + 1, r, opt, optr);
        };
        compute(compute, 0, n, 0, n);
    }
    cout << dp[k][n] << '\n';
    return 0;
}
