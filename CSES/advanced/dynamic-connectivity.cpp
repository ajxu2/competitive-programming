// created: 12-18-2025 Thu 04:31 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct DSURollback {
    int n, components;
    V<int> par, sz;
    stack<pair<int, int>> unites; // (small, big)
    DSURollback(int _n) {
        n = _n;
        par.resize(n);
        iota(begin(par), end(par), 0);
        sz.assign(n, 1);
        components = n;
    }
    int find(int x) {
        return par[x] == x ? x : find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (sz[x] > sz[y])
            swap(x, y);
        unites.push({x, y});
        if (x == y)
            return false;
        sz[y] += sz[x];
        par[x] = y;
        components--;
        return true;
    }
    bool rollback() {
        auto [x, y] = unites.top();
        unites.pop();
        if (x == y)
            return false;
        par[x] = x;
        sz[y] -= sz[x];
        components++;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    map<array<int, 2>, int> add_time;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        if (u > v)
            swap(u, v);
        add_time[{u, v}] = 0;
    }
    V<array<int, 4>> edges; // (u, v, add, remove)
    for (int i = 0; i < k; i++) {
        int t, u, v; cin >> t >> u >> v; u--, v--;
        if (u > v)
            swap(u, v);
        if (t == 1) {
            add_time[{u, v}] = i + 1;
        } else {
            auto it = add_time.find({u, v});
            edges.push_back({u, v, it->second, i + 1});
            add_time.erase(it);
        }
    }
    for (auto [e, t] : add_time)
        edges.push_back({e[0], e[1], t, k + 1});
    int tree_n = 1;
    while (tree_n < k + 1)
        tree_n *= 2;
    V<V<array<int, 2>>> tree(2 * tree_n);
    for (auto [u, v, add, remove] : edges) {
        add += tree_n;
        remove += tree_n;
        while (add < remove) {
            if (add % 2 == 1)
                tree[add++].push_back({u, v});
            if (remove % 2 == 1)
                tree[--remove].push_back({u, v});
            add /= 2;
            remove /= 2;
        }
    }
    V<int> ans(tree_n);
    DSURollback dsu(n);
    auto dfs = [&](auto&& self, int node) -> void {
        for (auto [u, v] : tree[node])
            dsu.unite(u, v);
        if (node >= tree_n) {
            ans[node - tree_n] = dsu.components;
        } else {
            self(self, 2 * node);
            self(self, 2 * node + 1);
        }
        for (int i = 0; i < ssize(tree[node]); i++)
            dsu.rollback();
    };
    dfs(dfs, 1);
    for (int i = 0; i < k + 1; i++)
        cout << ans[i] << " \n"[i == k];
    return 0;
}
