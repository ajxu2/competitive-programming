// created: 01-06-2025 Mon 02:46 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

void solve() {
    int n, q; cin >> n >> q;
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> p(n, 0), depth(n, 0);
    auto dfs = [&](auto&& self, int x, int par) -> void {
        for (int i : adj[x]) {
            if (i == par) continue;
            p[i] = x;
            depth[i] = depth[x] + 1;
            self(self, i, x);
        }
    };
    dfs(dfs, 0, 0);
    while (q--) {
        int v, c; cin >> v >> c; v--;
        int ptr = p[v];
        V<int> degs;
        while (ptr != 0) {
            degs.push_back(ssize(adj[ptr]));
            ptr = p[p[ptr]];
        }
        sort(begin(degs), end(degs));
        for (int i = 0; i < min((int)ssize(degs), c); i++) {
            degs[ssize(degs) - i - 1] = 1;
        }
        ll ans = 1 + 2 * accumulate(begin(degs), end(degs), 0LL);
        if (depth[v] % 2 == 0) ans--;
        ans %= MOD;
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
