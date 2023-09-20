// created: 09-18-2023 Mon 08:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> dp(n, 0);
    function<void(int, int)> dfs = [&](int x, int p) {
        for (int i : adj[x]) {
            if (i == p) continue;
            dfs(i, x);
            dp[x] += dp[i];
        }
        if (dp[x] == 0) dp[x] = 1;
    };
    dfs(0, -1);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; x--, y--;
        cout << (ll)dp[x] * dp[y] << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
