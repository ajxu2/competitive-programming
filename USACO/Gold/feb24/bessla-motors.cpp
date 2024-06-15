// created: 06-02-2024 Sun 12:53 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

struct DijkstraState {
    ll d; int x, src;
    bool operator<(const DijkstraState& o) const { return d > o.d; }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, c, r, k; cin >> n >> m >> c >> r >> k;
    V<V<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    priority_queue<DijkstraState> pq;
    V<ll> dist(n, 1e18); V<set<int>> cnt(n);
    for (int i = 0; i < c; i++) pq.push({0, i, i});
    while (!pq.empty()) {
        DijkstraState cur = pq.top(); pq.pop();
        if (sz(cnt[cur.x]) >= k || cnt[cur.x].count(cur.src)) continue;
        cnt[cur.x].insert(cur.src); dist[cur.x] = cur.d;
        for (array<int, 2> i : adj[cur.x]) pq.push({cur.d + i[1], i[0], cur.src});
    }
    V<int> ans;
    for (int i = c; i < n; i++) if (dist[i] <= r) ans.push_back(i);
    cout << sz(ans) << '\n';
    for (int i : ans) cout << i + 1 << '\n';
    return 0;
}
