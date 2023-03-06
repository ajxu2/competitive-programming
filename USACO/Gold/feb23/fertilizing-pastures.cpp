// created: 02-26-2023 Sun 04:21 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    V<V<int>> children(n);
    V<ll> a(n, 0);
    for (int i = 1; i < n; i++) {
        int j; cin >> j >> a[i]; j--;
        children[j].push_back(i);
    }
    V<ll> mins(n, 0), rate = a, dp(n, 0), pd(n, 9e18), maxd(n, 0);
    for (int i = n-1; i >= 0; i--) {
        V<array<ll, 3>> cand;
        for (int j : children[i]) {
            cand.push_back({mins[j] + 2, rate[j], j});
            mins[i] += (mins[j] + 2);
            rate[i] += rate[j];
            maxd[i] = max(maxd[i], maxd[j] + 1);
        }
        // proven greedy
        sort(cand.begin(), cand.end(), [](const array<ll, 3>& a, const array<ll, 3>& b) { return a[0] * b[1] < b[0] * a[1]; });
        V<ll> sfx; // sfx[i] = sum rates [i, end]
        for (array<ll, 3> j : cand) sfx.push_back(j[1]);
        for (int j = sfx.size() - 2; j >= 0; j--) sfx[j] += sfx[j+1];
        sfx.push_back(0);
        int cur = 0;
        for (int j = 0; j < cand.size(); j++) {
            int child = cand[j][2];
            cur++;
            if (maxd[i] == maxd[child] + 1) {
                // we can end at this node
                // pd[i] = savings
                pd[i] = min(pd[i], -(cur * rate[child] + dp[child]) - ((mins[child] + 2) * sfx[j+1]) + ((mins[i] - mins[child] - 1) * rate[child] + pd[child]));
            }
            dp[i] += cur * rate[child] + dp[child];
            cur += (mins[child] + 1);
        }
        if (pd[i] == 9e18) pd[i] = 0;
        pd[i] += dp[i];
    }
    if (t == 0) cout << 2*(n-1) << " " << dp[0] << "\n";
    else cout << 2*(n-1) - maxd[0] << " " << pd[0] << "\n";
    return 0;
}
