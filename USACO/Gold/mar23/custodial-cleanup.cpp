// created: 12-18-2023 Mon 12:07 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, m; cin >> n >> m;
    V<int> c(n), s(n), f(n);
    for (int& i : c) {
        cin >> i; i--;
    }
    for (int& i : s) {
        cin >> i; i--;
    }
    for (int& i : f) {
        cin >> i; i--;
    }
    V<V<int>> adj(n, V<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<bool> vis(n, 0), colors(n, 0), actualvis(n, 0);
    V<V<int>> todo(n, V<int>()); // todo for each color
    queue<int> q;
    q.push(0); vis[0] = 1;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        actualvis[p] = 1; colors[s[p]] = 1;
        // get next nodes
        for (int i : adj[p]) {
            if (vis[i]) continue;
            vis[i] = 1;
            if (colors[c[i]]) q.push(i);
            else todo[c[i]].push_back(i);
        }
        for (int i : todo[s[p]]) q.push(i);
        todo[s[p]].clear();
    }
    // check
    for (int i = 0; i < n; i++) {
        if (!actualvis[i] && s[i] != f[i]) {
            cout << "NO\n";
            return;
        }
    }
    // BFS again!!
    vis.assign(n, 0); colors.assign(n, 0); todo.assign(n, V<int>());
    V<bool> actualvis2(n, 0);
    while (!q.empty()) q.pop();
    q.push(0); vis[0] = 1;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        actualvis2[p] = 1; colors[f[p]] = 1;
        // get next nodes
        for (int i : adj[p]) {
            if (!actualvis[i] || vis[i]) continue;
            vis[i] = 1;
            if (colors[c[i]] || c[i] == f[i]) q.push(i);
            else todo[c[i]].push_back(i);
        }
        for (int i : todo[f[p]]) q.push(i);
        todo[f[p]].clear();
    }
    // check
    for (int i = 0; i < n; i++) {
        if (actualvis[i] && !actualvis2[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
