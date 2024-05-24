// created: 05-22-2024 Wed 03:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k1, k2, n; cin >> n >> k1 >> k2;
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<deque<int>> d(n, deque<int>(1, 0)); // d[i][j] stores nodes in st of i with depth >= j
    ll ans = 0;
    auto dfs = [&](auto&& self, int x, int p) -> void {
        deque<int> cur(1, 0);
        for (int i : adj[x]) {
            if (i == p) continue;
            self(self, i, x);
            // swap
            if (sz(d[i]) > sz(cur)) swap(cur, d[i]);
            // add
            for (int j = 0; j < sz(d[i]) - 1; j++) {
                int bound1 = k1 - j - 2, bound2 = k2 - j - 1;
                bound1 = clamp(bound1, 0, sz(cur) - 1); bound2 = clamp(bound2, 0, sz(cur) - 1);
                ans += (ll)(d[i][j] - d[i][j+1]) * (cur[bound1] - cur[bound2]);
            }
            // merge
            for (int j = 0; j < sz(d[i]); j++) cur[j] += d[i][j];
        }
        // increase depths
        cur.push_front(cur.front() + 1);
        int bound1 = clamp(k1, 0, sz(cur) - 1), bound2 = clamp(k2 + 1, 0, sz(cur) - 1);
        ans += cur[bound1] - cur[bound2];
        swap(cur, d[x]);
    };
    dfs(dfs, 0, -1);
    cout << ans << '\n';
    return 0;
}
