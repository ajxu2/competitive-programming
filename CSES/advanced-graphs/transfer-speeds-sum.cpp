// created: 08-11-2025 Mon 11:47 PM

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
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (-e[x] < -e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
    int size(int x) {
        return -e[find(x)];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<int, 3>> edges(n-1);
    for (auto& [a, b, x] : edges) {
        cin >> a >> b >> x; a--, b--;
    }
    sort(begin(edges), end(edges), [](array<int, 3> a, array<int, 3> b) {
        return a[2] > b[2];
    });
    ll ans = 0;
    DSU dsu(n);
    for (auto [a, b, x] : edges) {
        ans += (ll)x * dsu.size(a) * dsu.size(b);
        dsu.unite(a, b);
    }
    cout << ans << '\n';
    return 0;
}
