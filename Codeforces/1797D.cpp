// created: 07-28-2023 Fri 03:59 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<ll> imp(n, 0);
    V<int> sz(n, 0), par(n);
    V<set<array<int, 2>>> owo(n);
    function<void(int, int)> dfs = [&](int x, int p) {
        for (int i : adj[x]) {
            if (i == p) continue;
            dfs(i, x);
            imp[x] += imp[i];
            sz[x] += sz[i];
            owo[x].insert({sz[i], -i});
        }
        imp[x] += a[x];
        sz[x]++;
        par[x] = p;
    };
    dfs(0, -1);
    for (int i = 0; i < m; i++) {
        int t, x; cin >> t >> x; x--;
        if (t == 1) cout << imp[x] << "\n";
        else {
            // heavy son is the last one in the owo set
            if (owo[x].empty()) continue;
            int heavy = -(*owo[x].rbegin())[1];
            assert(owo[par[x]].erase(array<int, 2>{sz[x], -x}) == 1);
            assert(owo[x].erase(array<int, 2>{sz[heavy], -heavy}) == 1);
            sz[x] -= sz[heavy]; sz[heavy] += sz[x];
            owo[heavy].insert({sz[x], -x});
            owo[par[x]].insert({sz[heavy], -heavy});
            imp[x] -= imp[heavy]; imp[heavy] += imp[x];
            par[heavy] = par[x]; par[x] = heavy;
        }
    }
    return 0;
}
