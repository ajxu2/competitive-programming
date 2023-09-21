// created: 09-19-2023 Tue 10:07 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

struct DSU {
    int n;
    V<int> par, sz;
    V<char> ok;
    DSU(int _n) {
        n = _n;
        par = V<int>(n); iota(begin(par), end(par), 0);
        sz = V<int>(n, 1);
        ok = V<char>(n, 0);
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x; sz[x] += sz[y]; ok[x] |= ok[y];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> order(n);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&a](int x, int y) { return a[x] < a[y]; });
    DSU d(n);
    V<char> active(n, 0);
    for (int i : order) {
        active[i] = 1;
        if (a[i] == 0) d.ok[i] = 1;
        for (int j : adj[i]) {
            if (!active[j] || d.find(i) == d.find(j)) continue;
            d.ok[d.find(j)] &= (d.sz[d.find(j)] >= a[i]);
            d.unite(i, j);
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (d.find(i) != d.find(i+1)) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!d.ok[d.find(i)]) {
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
