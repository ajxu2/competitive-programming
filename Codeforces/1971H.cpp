// created: 06-30-2024 Sun 11:10 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct TwoSat {
    int n;
    V<V<int>> adj, radj;
    V<bool> solution, vis;
    V<int> order, scc;
    TwoSat(int _n) {
        n = _n;
        adj.resize(2*n); radj.resize(2*n);
    }
    int inv(int x) { return x < n ? x + n : x - n; }
    void add(int a, int b) {
        if (a < 0) a = ~a + n;
        if (b < 0) b = ~b + n;
        adj[inv(a)].push_back(b);
        adj[inv(b)].push_back(a);
        radj[a].push_back(inv(b));
        radj[b].push_back(inv(a));
    }
    // below functions for computing SCCs
    void dfs1(int x) {
        vis[x] = true;
        for (int i : adj[x]) {
            if (vis[i]) continue;
            dfs1(i);
        }
        order.push_back(x);
    }
    void dfs2(int x, int comp) {
        vis[x] = true; scc[x] = comp;
        for (int i : radj[x]) {
            if (vis[i]) continue;
            dfs2(i, comp);
        }
    }
    bool solve() {
        vis.assign(2*n, false); order.clear();
        for (int i = 0; i < 2*n; i++) {
            if (vis[i]) continue;
            dfs1(i);
        }
        reverse(begin(order), end(order));
        int cur = 0; vis.assign(2*n, false);
        scc.resize(2*n);
        for (int i : order) {
            if (vis[i]) continue;
            dfs2(i, cur++);
        }
        solution.resize(n);
        for (int i = 0; i < n; i++) {
            if (scc[i] == scc[i+n]) return false;
            solution[i] = scc[i] > scc[i+n];
        }
        return true;
    }
};

void solve() {
    int n; cin >> n;
    array<V<int>, 3> a;
    for (int i = 0; i < 3; i++) {
        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0) a[i][j]--;
        }
    }
    TwoSat sat(n);
    for (int i = 0; i < n; i++) {
        sat.add(a[0][i], a[1][i]);
        sat.add(a[1][i], a[2][i]);
        sat.add(a[2][i], a[0][i]);
    }
    cout << (sat.solve() ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
