// created: 11-05-2023 Sun 08:38 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, m, k; cin >> n >> m >> k;
    V<int> h(n);
    for (int& i : h) cin >> i;
    V<V<int>> adj(n);
    V<int> in(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); in[v]++;
    }
    // do a toposort
    V<int> topo;
    queue<int> q;
    V<int> in0;
    for (int i = 0; i < n; i++) if (in[i] == 0) {
        q.push(i);
        in0.push_back(i);
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        topo.push_back(p);
        for (int i : adj[p]) {
            in[i]--;
            if (in[i] == 0) q.push(i);
        }
    }
    // now do some dp
    V<ll> dp(n, 0);
    for (int i = n-1; i >= 0; i--) {
        int cur = topo[i];
        if (sz(adj[cur]) == 0) continue;
        for (int j : adj[cur]) {
            if (h[cur] <= h[j]) dp[cur] = max(dp[cur], h[j] - h[cur] + dp[j]);
            else dp[cur] = max(dp[cur], h[j] + k - h[cur] + dp[j]);
        }
    }
    sort(begin(in0), end(in0), [&h](int i, int j) { return h[i] < h[j]; });
    ll mx = 0;
    for (int i : in0) mx = max(mx, h[i] + dp[i]);
    ll ans = mx - h[in0[0]];
    for (int i = 1; i < sz(in0); i++) {
        mx = max(mx, h[in0[i-1]] + dp[in0[i-1]] + k);
        ans = min(ans, mx - h[in0[i]]);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
