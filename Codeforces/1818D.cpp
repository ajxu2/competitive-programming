// created: 06-18-2023 Sun 09:50 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

const int INF = 1'000'000'000;

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> cyc(10000, 0); // minimum cycle, the initialization makes sense i swear
    for (int i = 0; i < n; i++) {
        if (sz(adj[i]) < 4) continue;
        // BFS from all neighbors of this node
        for (int j : adj[i]) {
            V<int> d(n, INF), par(n);
            queue<int> q;
            q.push(j); d[j] = 0; par[j] = i;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int k : adj[cur]) {
                    if (k == i || d[k] != INF) continue;
                    q.push(k); d[k] = d[cur] + 1; par[k] = cur;
                }
            }
            for (int k : adj[i]) {
                if (k == j) continue;
                if (d[k] + 2 < sz(cyc)) {
                    cyc.clear();
                    cyc.push_back(k);
                    while (cyc.back() != i) cyc.push_back(par[cyc.back()]);
                }
            }
        }
    }
    if (sz(cyc) == 10000) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << sz(cyc)+2 << "\n";
        for (int i = 0; i < sz(cyc); i++) cout << cyc[i]+1 << " " << cyc[(i+1)%sz(cyc)]+1 << "\n";
        int cnt = 0;
        for (int i : adj[cyc.back()]) {
            if (find(cyc.begin(), cyc.end(), i) == cyc.end()) { // lol
                cout << cyc.back()+1 << " " << i+1 << "\n";
                cnt++;
            }
            if (cnt == 2) break;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
