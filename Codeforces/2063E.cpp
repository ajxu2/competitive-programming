// created: 02-18-2025 Tue 02:36 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    // first reduce to finding sum over all pairs min(d(u, lca), d(v, lca))
    // then loop over the possible lca
    // then when we sum the min, we can sum from i=1 to infty number of pairs with both dists >= i
    // then use small to large profit???
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<deque<int>> suffixDepth(n);
    V<int> subtreeSize(n, 1);
    ll ans = 0;
    auto dfs = [&](auto&& self, int x, int p) -> void {
        for (int i : adj[x]) {
            if (i != p) {
                self(self, i, x);
                subtreeSize[x] += subtreeSize[i];
            }
        }
        deque<int> cur = {0};
        for (int i : adj[x]) {
            if (ssize(suffixDepth[i]) > ssize(cur)) swap(suffixDepth[i], cur);
            // count
            auto it1 = begin(suffixDepth[i]), it2 = begin(cur);
            while (it1 != end(suffixDepth[i])) {
                ans += (ll)*it1 * *it2;
                it1++;
                it2++;
            }
            // merge
            it1 = begin(suffixDepth[i]), it2 = begin(cur);
            while (it1 != end(suffixDepth[i])) {
                *it2 += *it1;
                it1++;
                it2++;
            }
        }
        cur.push_front(cur.front() + 1);
        swap(suffixDepth[x], cur);
    };
    dfs(dfs, 0, -1);
    ans *= 2;
    ans -= (ll)n * (n - 1) / 2;
    ans += accumulate(begin(subtreeSize), end(subtreeSize), 0LL) - n;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
