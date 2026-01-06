// created: 01-06-2026 Tue 11:40 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> c(m);
    for (int& i : c)
        cin >> i;
    V<V<array<int, 2>>> adj(n + m); // 0..n-1 cities, n..n+m-1 bus companies
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int u; cin >> u; u--;
            adj[u].push_back({i + n, c[i]});
            adj[i + n].push_back({u, 0});
        }
    }
    V<ll> d(n + m, INF);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        du = -du;
        pq.pop();
        if (du >= d[u])
            continue;
        d[u] = du;
        for (auto [v, w] : adj[u])
            pq.push({-(du + w), v});
    }
    for (int i = 0; i < n; i++)
        cout << d[i] << " \n"[i == n - 1];
    return 0;
}
