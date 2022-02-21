// created: 02-20-2022 Sun 08:35 PM

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        sz.resize(n);
        fill(sz.begin(), sz.end(), 1);
    }
    // find representative of a node with path compression
    int find(int x) {
        stack<int> tmp;
        while (parent[x] != x) {
            tmp.push(x);
            x = parent[x];
        }
        while (!tmp.empty()) {
            parent[tmp.top()] = x;
            tmp.pop();
        }
        return x;
    }
    // find if two nodes are in the same CC
    bool same(int x, int y) {
        return (find(x) == find(y));
    }
    // unite two sets by size
    // returns true if any CCs were united
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        // x big y small
        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        return true;
    }
    // get the size of a CC
    int size(int node) {
        return sz[find(node)];
    }
};

struct Edge {
    int a, b, w;
};

void kruskal() {
    int n, m; cin >> n >> m;
    vector<Edge> a(m);
    DSU b(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a[i].a >> a[i].b >> a[i].w;
        b.unite(a[i].a, a[i].b);
    }
    if (b.size(1) != n) { // not connected
        cout << "IMPOSSIBLE\n";
        return;
    }
    sort(a.begin(), a.end(), [](const Edge& x, const Edge& y){ return x.w > y.w; });
    DSU c(n+1);
    long long ans = 0;
    for (int i = 0; i < n-1;) {
        Edge tmp = a.back();
        a.pop_back();
        if (c.unite(tmp.a, tmp.b)) {
            i++;
            ans += tmp.w;
        }
    }
    cout << ans << "\n";
}

void prim() {
    int n, m; cin >> n >> m;
    vector<vector<array<int, 2>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    vector<bool> visited(n+1, false);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq; // (weight, node)
    pq.push({0, 1});
    long long ans = 0;
    while (!pq.empty()) {
        array<int, 2> process = pq.top();
        pq.pop();
        if (visited[process[1]]) continue;
        visited[process[1]] = true;
        ans += process[0];
        for (array<int, 2> j : adj[process[1]]) pq.push(j);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { // not connected
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << ans << "\n";
}

int main() {
    mt19937 rng((uint64_t) new char);
    if (uniform_int_distribution<>(1,2)(rng) == 1) kruskal();
    else prim();
    return 0;
}
