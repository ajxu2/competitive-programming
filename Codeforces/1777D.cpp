// created: 07-31-2023 Mon 12:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

const int MOD = 1'000'000'007;

ll fexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> maxd(n, 0);
    function<void(int, int)> dfs = [&](int x, int p) {
        for (int i : adj[x]) {
            if (i == p) continue;
            dfs(i, x);
            maxd[x] = max(maxd[x], maxd[i]+1);
        }
    };
    dfs(0, -1);
    ll ans = 0;
    for (int i : maxd) ans = (ans + i + 1) % MOD;
    cout << ans * fexp(2, n-1) % MOD << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
