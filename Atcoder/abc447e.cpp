// created: 03-02-2026 Mon 08:09 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

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
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y)
            return;
        if (-e[x] > -e[y])
            swap(x, y);
        e[y] += e[x];
        e[x] = y;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<array<int, 2>> edges(m);
    for (auto& [u, v] : edges) {
        cin >> u >> v; u--, v--;
    }
    DSU dsu(n);
    int cc = n;
    V<int> pow2(m + 1, 1);
    for (int i = 1; i <= m; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    int ans = 0;
    for (int i = m - 1; i >= 0; i--) {
        auto [u, v] = edges[i];
        if (cc == 2 && !dsu.same(u, v))
            (ans += pow2[i + 1]) %= MOD;
        if (cc > 2 && !dsu.same(u, v)) {
            dsu.unite(u, v);
            cc--;
        }
    }
    cout << ans << '\n';
    return 0;
}
