// created: 12-19-2024 Thu 02:54 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

void solve() {
    // key idea: elsie's optimal path consists of doing stuff before s,
    // then making a jump to get ahead of bessie
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) adj[i].push_back(i+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }
    // find shortest paths to all nodes
    V<int> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            dist[j] = min(dist[j], dist[i] + 1);
        }
    }
    // assign each jump a "score": node jumped to - dist to get there
    cout << 1;
    set<int> scores;
    for (int i = 0; i < n-2; i++) {
        int cur_score = *max_element(begin(adj[i]), end(adj[i])) - dist[i];
        scores.insert(cur_score);
        // elsie wins iff there is a score greater than i+2
        if (scores.upper_bound(i+2) != end(scores)) cout << 0;
        else cout << 1;
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
