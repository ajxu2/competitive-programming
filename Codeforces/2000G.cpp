// created: 12-20-2024 Fri 05:34 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

bool overlap(ll l1, ll r1, ll l2, ll r2) {
    return l1 < r2 && r1 > l2;
}

void solve() {
    int n, m; cin >> n >> m;
    int t0, t1, t2; cin >> t0 >> t1 >> t2;
    V<V<array<int, 3>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, l1, l2; cin >> u >> v >> l1 >> l2; u--, v--;
        adj[u].push_back({v, l1, l2});
        adj[v].push_back({u, l1, l2});
    }
    V<ll> dist(n, INF);
    // run dijkstra's algorithm from node n-1
    priority_queue<pair<ll, int>> pq;
    pq.push({0, n-1});
    while (!empty(pq)) {
        pair<ll, int> cur = pq.top();
        pq.pop();
        ll cur_dist = -cur.first;
        int cur_node = cur.second;
        if (cur_dist >= dist[cur_node]) continue;
        dist[cur_node] = cur_dist;
        for (const array<int, 3>& i : adj[cur_node]) {
            int nxt = i[0], w1 = i[1], w2 = i[2];
            if (overlap(cur_dist, cur_dist + w1, t0 - t2, t0 - t1)) {
                pq.push({-(cur_dist + w2), nxt}); // walk
                pq.push({-(t0 - t1 + w1), nxt}); // wait for end of call
            } else {
                pq.push({-(cur_dist + w1), nxt});
            }
        }
    }
    ll ans = t0 - dist[0];
    cout << max(ans, -1LL) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
