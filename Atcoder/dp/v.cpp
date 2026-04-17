// created: 01-25-2026 Sun 10:15 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, mod; cin >> n >> mod;
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<ll> dp(n, 1); // number of ways for this subtree
    auto dfs = [&](this auto self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v != p) {
                self(v, u);
                (dp[u] *= dp[v] + 1) %= mod;
            }
        }
    };
    dfs(0, -1);
    V<ll> dp2(n, 0); // dp of par[u] if rooted at u
    auto dfs2 = [&](this auto self, int u, int p) -> void {
        V<int> children;
        for (int v : adj[u])
            if (v != p)
                children.push_back(v);
        int cnt = ssize(children);
        if (cnt == 0)
            return;
        V<ll> pre(cnt), suf(cnt);
        pre[0] = (dp[children[0]] + 1) % mod;
        for (int i = 1; i < cnt; i++)
            pre[i] = pre[i - 1] * (dp[children[i]] + 1) % mod;
        suf[cnt - 1] = (dp[children[cnt - 1]] + 1) % mod;
        for (int i = cnt - 2; i >= 0; i--)
            suf[i] = suf[i + 1] * (dp[children[i]] + 1) % mod;
        for (int i = 0; i < cnt; i++) {
            int v = children[i];
            dp2[v] = (dp2[u] + 1) % mod;
            if (i > 0)
                (dp2[v] *= pre[i - 1]) %= mod;
            if (i < cnt - 1)
                (dp2[v] *= suf[i + 1]) %= mod;
            self(v, u);
        }
    };
    dfs2(0, -1);
    for (int i = 0; i < n; i++)
        cout << (dp[i] * (dp2[i] + 1)) % mod << '\n';
    return 0;
}
