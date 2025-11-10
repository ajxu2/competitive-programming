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

struct Edge {
    int u, v, w, i;
    bool operator<(const Edge& o) {
        if (w == o.w)
            return i < o.i;
        return w < o.w;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    DSURollback dsu(n);
    V<Edge> edges(m);
    for (Edge& e : edges) {
        cin >> e.u >> e.v >> e.w; e.u--, e.v--;
        e.i = -1;
    }
    V<Edge> queries;
    for (int i = 0; i < q; i++) {
        int size_set; cin >> size_set;
        while (size_set--) {
            int e_idx; cin >> e_idx; e_idx--;
            Edge e = edges[e_idx];
            queries.push_back({e.u, e.v, e.w, i});
        }
    }
    sort(begin(edges), end(edges));
    sort(begin(queries), end(queries));
    V<bool> ans(q, true);
    int edges_l = 0, queries_l = 0;
    while (edges_l < m) {
        int cur_w = edges[edges_l].w;
        int edges_r = edges_l;
        while (edges_r < m && edges[edges_r].w == cur_w)
            edges_r++;
        int queries_r = queries_l;
        while (queries_r < ssize(queries) && queries[queries_r].w == cur_w)
            queries_r++;
        int cur_query_l = queries_l;
        while (cur_query_l < queries_r) {
            int cur_i = queries[cur_query_l].i;
            int cur_query_r = cur_query_l;
            while (cur_query_r < queries_r && queries[cur_query_r].i == cur_i)
                cur_query_r++;
            for (int i = cur_query_l; i < cur_query_r; i++) {
                auto [u, v, _, q_idx] = queries[i];
                if (!dsu.unite(u, v))
                    ans[q_idx] = false;
            }
            for (int i = cur_query_l; i < cur_query_r; i++)
                dsu.rollback();
            cur_query_l = cur_query_r;
        }
        for (int i = edges_l; i < edges_r; i++) {
            auto [u, v, _, __] = edges[i];
            dsu.unite(u, v);
        }
        edges_l = edges_r;
        queries_l = queries_r;
    }
    for (bool i : ans)
        cout << (i ? "YES" : "NO") << '\n';
    return 0;
}
