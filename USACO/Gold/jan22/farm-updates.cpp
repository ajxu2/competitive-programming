// created: 12-23-2022 Fri 12:48 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct Upd {
    char type;
    int x, y;
};

V<set<int>> adj;
V<bool> rel, vis, act;
V<int> ans;
bool found;

void dfs(int x, int y) {
    // mark everything in CC as relevant and set ans to y
    vis[x] = true; rel[x] = true; ans[x] = y;
    for (int i : adj[x]) if (!vis[i]) dfs(i, y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    adj.resize(n); rel = V<bool>(n, false); act = V<bool>(n, true);
    V<Upd> adds, upd;
    for (int i = 0; i < q; i++) {
        char type; cin >> type;
        if (type == 'D') {
            int x; cin >> x; x--;
            upd.push_back({type, x, 0});
            act[x] = false;
        } else if (type == 'A') {
            int x, y; cin >> x >> y; x--; y--;
            upd.push_back({type, x, y});
            adds.push_back({type, x, y});
            adj[x].insert(y); adj[y].insert(x);
        } else {
            int e; cin >> e; e--;
            int x = adds[e].x, y = adds[e].y;
            upd.push_back({type, x, y});
            adj[x].erase(y); adj[y].erase(x);
        }
    }
    vis = V<bool>(n, false);
    ans = V<int>(n, 0);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (act[i]) dfs(i, q);
    }
    vis = V<bool>(n, false);
    for (int i = q-1; i >= 0; i--) {
        Upd u = upd[i];
        if (u.type == 'D') {
            // activate this farm
            if (!rel[u.x]) dfs(u.x, i);
            act[u.x] = true;
        } else if (u.type == 'R') {
            // add edge
            if (rel[u.x] && !rel[u.y]) dfs(u.y, i);
            else if (!rel[u.x] && rel[u.y]) dfs(u.x, i);
            adj[u.x].insert(u.y); adj[u.y].insert(u.x);
        } else {
            // remove edge
            adj[u.x].erase(u.y); adj[u.y].erase(u.x);
        }
    }
    for (int i : ans) cout << i << "\n";
    return 0;
}
