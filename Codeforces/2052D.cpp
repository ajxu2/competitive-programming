// created: 01-13-2025 Mon 02:19 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<short> a(n);
    // 0 = uf, 1 = st, 2 = sf, 3 = ut
    for (int i = 0; i < n; i++) {
        string res, tmp;
        for (int j = 0; j < 2; j++) {
            cin >> tmp;
            res.push_back(tmp[0]);
        }
        if (res == "uf") a[i] = 0;
        else if (res == "st") a[i] = 1;
        else if (res == "sf") a[i] = 2;
        else a[i] = 3;
    }
    int m; cin >> m;
    V<V<int>> adj(n);
    V<int> indeg(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
        indeg[v]++;
    }
    array<queue<int>, 4> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q[a[i]].push(i);
        }
    }
    V<int> topo;
    int idx = 0;
    while (ssize(topo) < n) {
        while (empty(q[idx])) {
            idx++; idx %= 4;
        }
        int cur = q[idx].front();
        q[idx].pop();
        topo.push_back(cur);
        for (int i : adj[cur]) {
            indeg[i]--;
            if (indeg[i] == 0) {
                q[a[i]].push(i);
            }
        }
    }
    bool ok = true, cur = false;
    for (int i : topo) {
        if (cur) {
            if (a[i] == 3) cur = false;
            else if (a[i] != 2) ok = false;
        } else {
            if (a[i] == 1) cur = true;
            else if (a[i] != 0) ok = false;
        }
    }
    if (ok) {
        for (int i = 0; i < n; i++) cout << topo[i] + 1 << " \n"[i == n-1];
    } else cout << "-1\n";
    return 0;
}
