// created: 08-01-2026 Sat 08:06 AM

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
    int find(int u) {
        return e[u] < 0 ? u : e[u] = find(e[u]);
    }
    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v)
            return false;
        if (-e[u] < -e[v])
            swap(u, v);
        e[u] += e[v];
        e[v] = u;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    int mx = *max_element(begin(a), end(a));
    V<V<int>> factors(mx + 1);
    for (int i = 1; i <= mx; i++)
        for (int j = i; j <= mx; j += i)
            factors[j].push_back(i);
    V<V<int>> multiples(mx + 1);
    for (int i = 0; i < n; i++)
        for (int j : factors[a[i]])
            multiples[j].push_back(i);
    // kruskal's algorithm
    DSU dsu(n);
    ll ans = 0;
    for (int i = mx; i >= 1; i--)
        for (int j = 0; j < ssize(multiples[i]) - 1; j++)
            if (dsu.unite(multiples[i][j], multiples[i][j + 1]))
                ans += i;
    cout << ans << '\n';
    return 0;
}
