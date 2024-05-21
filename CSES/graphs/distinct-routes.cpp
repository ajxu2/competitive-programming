// created: 05-18-2024 Sat 11:07 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<int>> adj(n), fadj(n);
    V<V<int>> resid(n, V<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
        fadj[u].push_back(v);
        resid[u][v] = 1;
    }
    V<int> par(n, -1);
    auto dfs = [&](auto&& self, int x) -> void {
        for (int i : adj[x]) {
            if (par[i] != -1 || resid[x][i] == 0) continue;
            par[i] = x; self(self, i);
        }
    };
    int ansn = 0;
    while (true) {
        par.assign(n, -1); par[0] = 0;
        dfs(dfs, 0);
        if (par[n-1] == -1) break;
        int ptr = n-1, delta = INT_MAX;
        while (par[ptr] != ptr) {
            delta = min(delta, resid[par[ptr]][ptr]);
            ptr = par[ptr];
        }
        ptr = n-1;
        while (par[ptr] != ptr) {
            resid[par[ptr]][ptr] -= delta;
            resid[ptr][par[ptr]] += delta;
            ptr = par[ptr];
        }
        ansn += delta;
    }
    V<V<int>> adj2(n);
    for (int i = 0; i < n; i++) {
        for (int j : fadj[i]) if (resid[i][j] == 0) adj2[i].push_back(j);
    }
    V<V<int>> ans(ansn, V<int>(1, 0));
    for (int i = 0; i < ansn; i++) {
        int ptr = 0;
        while (ptr != n-1) {
            int tmp = adj2[ptr].back(); adj2[ptr].pop_back();
            ans[i].push_back(tmp); ptr = tmp;
        }
    }
    cout << ansn << '\n';
    for (V<int> i : ans) {
        cout << sz(i) << '\n';
        for (int j = 0; j < sz(i); j++) cout << i[j] + 1 << " \n"[j == sz(i)-1];
    }
    return 0;
}
