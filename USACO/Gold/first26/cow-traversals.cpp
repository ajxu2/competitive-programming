#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct DSU {
    int n;
    V<int> e;
    DSU(int _n) {
        n = _n;
        e.assign(n, -1);
    }
    int find(int x) {
        return e[x] < 0 ? x : e[x] = find(e[x]);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return false;
        if (-e[u] > -e[v])
            swap(u, v);
        e[v] += e[u];
        e[u] = v;
        return true;
    }
    int size(int x) {
        return -e[find(x)];
    }
};

int main() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i, i--;
    V<V<int>> radj(n);
    for (int i = 0; i < n; i++)
        radj[a[i]].push_back(i);
    int m; cin >> m;
    V<pair<int, char>> b(m), queries;
    V<char> state(n, 'X');
    for (auto& [c, v] : b) {
        cin >> c >> v, c--;
        queries.push_back({c, state[c]});
        state[c] = v;
    }
    reverse(begin(queries), end(queries));
    V<int> nxt(n, -1); // next house with a party
    V<int> vis(n, false);
    auto dfs = [&](auto&& self, int u, int src) -> void {
        if (vis[u])
            return;
        vis[u] = true;
        nxt[u] = src;
        for (int v : radj[u])
            if (state[v] == 'X')
                self(self, v, src);
    };
    for (int i = 0; i < n; i++)
        if (state[i] != 'X')
            dfs(dfs, i, i);
    array<int, 128> ans;
    ans.fill(0);
    DSU dsu(n);
    V<int> set_root(n);
    for (int i = 0; i < n; i++) {
        if (nxt[i] != -1) {
            ans[state[nxt[i]]]++;
            dsu.unite(i, nxt[i]);
            set_root[dsu.find(i)] = nxt[i];
        } else {
            set_root[i] = i;
        }
    }
    V<array<int, 3>> to_output;
    for (auto [c, v] : queries) {
        to_output.push_back({ans['C'], ans['O'], ans['W']});
        if (v != 'X') {
            int sz = dsu.size(c);
            ans[state[c]] -= sz;
            ans[v] += sz;
        } else {
            // unite
            int sz = dsu.size(c);
            ans[state[c]] -= sz;
            if (dsu.find(c) != dsu.find(a[c])) {
                int nxt2 = set_root[dsu.find(a[c])];
                ans[state[nxt2]] += sz;
                dsu.unite(c, a[c]);
                set_root[dsu.find(c)] = nxt2;
            }
        }
        state[c] = v;
    }
    reverse(begin(to_output), end(to_output));
    for (auto [c, o, w] : to_output)
        cout << c << ' ' << o << ' ' << w << '\n';
    return 0;
}
