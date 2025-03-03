// created: 03-03-2025 Mon 10:51 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

template<class T> void dbg(V<T> v) {
    cerr << "[";
    for (int i = 0; i < ssize(v); i++) {
        cerr << v[i];
        if (i != ssize(v) - 1) cerr << ", ";
    }
    cerr << "]\n";
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    V<V<array<int, 2>>> adj(n);
    V<int> weights = {0};
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
        weights.push_back(w);
    }
    sort(begin(weights), end(weights));
    weights.erase(unique(begin(weights), end(weights)), end(weights));
    // whar[u][v][k] = going from u to v, how many edges weight >weights[k]?
    V<V<V<int>>> whar(n, V<V<int>>(n, V<int>(ssize(weights), INT_MAX)));
    for (int u = 0; u < n; u++) {
        for (int k = 0; k < ssize(weights); k++) {
            // 0-1 BFS
            deque<array<int, 2>> bfs; bfs.push_back({u, 0});
            while (!bfs.empty()) {
                auto [cur, d] = bfs.front();
                bfs.pop_front();
                if (whar[u][cur][k] <= d) continue;
                whar[u][cur][k] = d;
                for (auto [v, w] : adj[cur]) {
                    if (w > weights[k]) bfs.push_back({v, d + 1});
                    else bfs.push_front({v, d});
                }
            }
        }
    }
    while (q--) {
        int a, b, k; cin >> a >> b >> k; a--, b--;
        // find first in whar[a][b] less than k
        int l = 0, r = ssize(weights);
        while (l < r) {
            int mid = midpoint(l, r);
            if (whar[a][b][mid] < k) r = mid;
            else l = mid + 1;
        }
        cout << weights[l] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
