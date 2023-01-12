// created: 01-01-2023 Sun 10:16 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

V<V<int>> adj;
V<bool> red, blue;
int n, d;

struct Subt {
    int red, blue, mxd, ans; // depth of node, num red, num blue, max depth of a colored node (rel to node), ans
    Subt(int _red, int _blue, int _mxd, int _ans) {
        red = _red; blue = _blue; mxd = _mxd; ans = _ans;
    }
};

Subt dfs(int x, int p) {
    Subt res(0, 0, -1e9, 0);
    for (int i : adj[x]) {
        if (i != p) {
            Subt ch = dfs(i, x);
            res.red += ch.red; res.blue += ch.blue; res.mxd = max(res.mxd, ch.mxd + 1);
            if (ch.red > 0 && ch.blue > 0) {
                // both pieces visit this
                res.ans += (ch.ans + 4);
            } else if ((ch.red == 0) ^ (ch.blue == 0)) {
                // only one piece visits
                if (ch.mxd + 1 <= d) res.ans += (ch.ans + 2); // red piece can go on own
                else res.ans += (ch.ans + 4); // blue piece must be dragged in
            }
        }
    }
    if (red[x]) {
        res.red++;
        if (res.mxd < 0) res.mxd = 0;
    }
    if (blue[x]) {
        res.blue++;
        if (res.mxd < 0) res.mxd = 0;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d;
    adj.resize(n); red = V<bool>(n, false); blue = V<bool>(n, false);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int j; cin >> j; red[j-1] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int j ; cin >> j; blue[j-1] = true;
    }
    cout << dfs(0, -1).ans << "\n";
    return 0;
}
