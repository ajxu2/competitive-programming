// created: 01-06-2026 Tue 11:02 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;
const int LOGMX = 20;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c; u--, v--;
        adj[u].push_back({v, c});
    }
    V<ll> d(n, INF);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});
    V<int> order; // vertices sorted by distance
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        du = -du;
        pq.pop();
        if (du >= d[u])
            continue;
        d[u] = du;
        order.push_back(u);
        for (auto [v, w] : adj[u])
            pq.push({-(du + w), v});
    }
    // compute shortest-paths subgraph
    V<V<int>> par(n);
    for (int i = 0; i < n; i++)
        for (auto [j, w] : adj[i])
            if (d[i] < INF && d[i] + w == d[j])
                par[j].push_back(i);
    // compute most recent node in every path
    V<V<int>> lift(LOGMX, V<int>(n, 0));
    V<int> depth(n);
    auto lca = [&](int u, int v) -> int {
        if (depth[u] > depth[v])
            swap(u, v);
        int diff = depth[v] - depth[u];
        for (int i = 0; i < LOGMX; i++)
            if ((diff >> i) & 1)
                v = lift[i][v];
        if (u == v)
            return u;
        for (int i = LOGMX - 1; i >= 0; i--)
            if (lift[i][u] != lift[i][v])
                u = lift[i][u], v = lift[i][v];
        return lift[0][u];
    };
    for (int i : order) {
        if (i == 0)
            continue;
        int res = -1;
        for (int j : par[i]) {
            if (res == -1)
                res = j;
            else
                res = lca(res, j);
        }
        lift[0][i] = res;
        for (int j = 1; j < LOGMX; j++)
            lift[j][i] = lift[j - 1][lift[j - 1][i]];
        depth[i] = depth[res] + 1;
    }
    V<int> ans;
    for (int i = n - 1; i != lift[0][i]; i = lift[0][i])
        ans.push_back(i);
    ans.push_back(0);
    sort(begin(ans), end(ans));
    cout << ssize(ans) << '\n';
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}
