// created: 12-16-2025 Tue 04:05 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

struct PrefixSum {
    V<ll> p;
    PrefixSum(const V<ll>& a) {
        int n = ssize(a);
        p.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] + a[i - 1];
    }
    ll qry(int l, int r) { return p[r] - p[l]; }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<ll> a(n);
    for (ll& i : a)
        cin >> i;
    V<ll> ia(n);
    for (int i = 0; i < n; i++)
        ia[i] = i * a[i];
    PrefixSum pa(a), pia(ia);
    auto cost = [&](int l, int r) { // cost [l, r], schools at l and r
        int m = midpoint(l, r);
        return pia.qry(l, m + 1) - l * pa.qry(l, m + 1) + r * pa.qry(m + 1, r + 1) - pia.qry(m + 1, r + 1);
    };
    V<V<ll>> dp(k + 1, V<ll>(n, INF));
    // dp[k][n] = min cost of [0, n], k schools, with a school at n
    for (int i = 0; i < n; i++)
        dp[1][i] = i * pa.qry(0, i + 1) - pia.qry(0, i + 1);
    for (int i = 2; i <= k; i++) {
        auto compute = [&](auto&& self, int l, int r, int optl, int optr) -> void {
            // inclusive [l, r], [optl, optr]
            if (l > r)
                return;
            int mid = midpoint(l, r);
            int opt = -1;
            ll optval = INF;
            for (int j = optl; j <= min(mid - 1, optr); j++) {
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
        compute(compute, i - 1, n - 1, 0, n - 1);
    }
    ll ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[k][i] + pia.qry(i, n) - i * pa.qry(i, n));
    cout << ans << '\n';
    return 0;
}
