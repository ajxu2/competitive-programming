// created: 08-12-2025 Tue 12:02 AM

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
};

struct Edge {
    int a, b, w, i;
    bool operator<(const Edge& e) {
        return w < e.w;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        edges[i] = {a, b, w, i};
    }
    sort(begin(edges), end(edges));
    V<bool> ans(m);
    DSU dsu(n);
    int l = 0;
    while (l < m) {
        int r = l;
        while (r < m && edges[l].w == edges[r].w)
            r++;
        for (int i = l; i < r; i++)
            ans[edges[i].i] = dsu.find(edges[i].a) != dsu.find(edges[i].b);
        for (int i = l; i < r; i++)
            dsu.unite(edges[i].a, edges[i].b);
        l = r;
    }
    for (int i = 0; i < m; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';
    return 0;
}
