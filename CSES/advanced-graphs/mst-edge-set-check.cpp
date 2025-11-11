// created: 11-10-2025 Mon 09:43 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct DSURollback {
    int n;
    V<int> par, sz;
    stack<pair<int, int>> unites; // (small, big)
    DSURollback(int _n) {
        n = _n;
        par.resize(n);
        iota(begin(par), end(par), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        return par[x] == x ? x : find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (sz[x] > sz[y])
            swap(x, y);
        unites.push({x, y});
        if (x == y) {
            return false;
        }
        sz[y] += sz[x];
        par[x] = y;
        return true;
    }
    void rollback() {
        auto [x, y] = unites.top();
        unites.pop();
        if (x == y)
            return;
        par[x] = x;
        sz[y] -= sz[x];
    }
};

using Edge = array<int, 2>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    map<int, V<Edge>> edges;
    V<array<int, 3>> edges_by_idx(m);;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        edges[w].push_back({u, v});
        edges_by_idx[i] = {u, v, w};
    }
    map<int, map<int, V<Edge>>> queries;
    for (int i = 0; i < q; i++) {
        int size_set; cin >> size_set;
        while (size_set--) {
            int e_idx; cin >> e_idx; e_idx--;
            auto [u, v, w] = edges_by_idx[e_idx];
            queries[w][i].push_back({u, v});
        }
    }
    DSURollback dsu(n);
    V<bool> ans(q, true);
    for (auto [w, edges_w] : edges) {
        for (auto [i, queries_wi] : queries[w]) {
            for (auto [u, v] : queries_wi) {
                if (!dsu.unite(u, v))
                    ans[i] = false;
            }
            for (auto _ : queries_wi)
                dsu.rollback();
        }
        for (auto [u, v] : edges_w)
            dsu.unite(u, v);
    }
    for (bool i : ans)
        cout << (i ? "YES" : "NO") << '\n';
    return 0;
}
