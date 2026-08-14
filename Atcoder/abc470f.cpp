// created: 08-08-2026 Sat 08:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

ll fexp(ll a, int b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return fexp(a, MOD - 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<ll> fact(n + 1), ifact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    array<int, 26> freq;
    V<bool> vis(n, false);
    auto dfs = [&](this auto self, int u) -> void {
        if (vis[u])
            return;
        vis[u] = true;
        freq[s[u] - 'a']++;
        for (int v : adj[u])
            self(v);
    };
    bool found_identical = false;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        freq.fill(0);
        dfs(i);
        int sum = 0;
        for (int j : freq) {
            sum += j;
            if (j >= 2)
                found_identical = true;
        }
        (ans *= fact[sum]) %= MOD;
        for (int j : freq)
            (ans *= ifact[j]) %= MOD;
    }
    if (!found_identical)
        (ans *= ifact[2]) %= MOD;
    cout << ans << '\n';
    return 0;
}
