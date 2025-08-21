// created: 08-20-2025 Wed 05:34 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

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
    bool unite(int x, int y) {
        // return true iff any CCs were united
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (-e[x] < -e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // a tree has 1 eulerian subgraph,
    // and each extra edge contributes a factor of 2
    int n, m; cin >> n >> m;
    DSU dsu(n);
    int ans = 1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        if (!dsu.unite(u, v))
            (ans *= 2) %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
