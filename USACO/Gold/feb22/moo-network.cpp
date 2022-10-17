// created: 10-17-2022 Mon 01:08 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) par.push_back(i);
        sz = vector<int>(n, 1);
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

struct Edge {
    int a, b; ll w;
    bool operator<(const Edge& e) { return w < e.w; }
};

int main() {
    int n; cin >> n;
    vector<array<int, 2>> cows(n);
    for (int i = 0; i < n; i++) cin >> cows[i][0] >> cows[i][1];
    sort(cows.begin(), cows.end());
    // for each cow, figure out cows it can connect to s.t. x is lesser
    vector<int> lst(11, -1);
    vector<Edge> el;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) {
            if (lst[j] == -1) continue;
            int ji = lst[j];
            el.push_back({i, ji, (ll)(cows[i][0]-cows[ji][0])*(cows[i][0]-cows[ji][0]) + (ll)(cows[i][1]-cows[ji][1])*(cows[i][1]-cows[ji][1])});
        }
        lst[cows[i][1]] = i;
    }
    // Kruskal
    sort(el.begin(), el.end());
    DSU d(n);
    ll ans = 0;
    for (Edge i : el) if (d.unite(i.a, i.b)) ans += i.w;
    cout << ans << "\n";
    return 0;
}
