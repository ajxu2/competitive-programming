// created: 01-07-2026 Wed 09:48 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> depth(n, 0), par(n, 0);
    auto dfs = [&](this auto self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                par[v] = u;
                self(v, u);
            }
        }
    };
    dfs(0, -1);
    V<int> freq_depth(n, 0);
    for (int i = 0; i < n; i++)
        freq_depth[depth[i]]++;
    int ans = *max_element(begin(freq_depth), end(freq_depth));
    for (int i = 0; i < n; i++) {
        int children = ssize(adj[i]);
        if (i != 0)
            children--;
        if (children == ans) {
            ans++;
            break;
        }
    }
    V<V<int>> layers(n);
    for (int i = 0; i < n; i++)
        layers[depth[i]].push_back(i);
    V<int> color(n, -1);
    color[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        // color layer i + 1 using layer i
        V<int> relevant;
        for (int u : layers[i]) {
            int children = ssize(adj[u]);
            if (u != 0)
                children--;
            if (children > 0)
                relevant.push_back(u);
        }
        if (ssize(relevant) == 0)
            break;
        if (ssize(relevant) == 1) {
            int forbidden = color[relevant[0]];
            int cur_color = 0;
            for (int v : layers[i + 1]) {
                if (cur_color == forbidden)
                    cur_color++;
                color[v] = cur_color;
                cur_color++;
            }
        } else {
            set<int> can_use;
            for (int j = 0; j < ssize(layers[i + 1]) + 5; j++)
                can_use.insert(j);
            int l = ssize(relevant);
            for (int j = 0; j < l; j++) {
                int u = relevant[j];
                int child = -1;
                for (int v : adj[u]) {
                    if (v != par[u]) {
                        child = v;
                        break;
                    }
                }
                if (child != -1) {
                    color[child] = color[relevant[(j + 1) % l]];
                    can_use.erase(color[child]);
                }
            }
            for (int u : layers[i]) {
                for (int v : adj[u]) {
                    if (v == par[u] || color[v] != -1)
                        continue;
                    auto it = begin(can_use);
                    if (*it == color[u])
                        it++;
                    color[v] = *it;
                    can_use.erase(it);
                }
            }
        }
    }
    V<V<int>> groups(ans);
    for (int i = 0; i < n; i++) {
        assert(color[i] < ans);
        groups[color[i]].push_back(i);
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << ssize(groups[i]) << ' ';
        for (int j : groups[i])
            cout << j + 1 << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
