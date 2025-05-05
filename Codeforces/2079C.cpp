// created: 05-05-2025 Mon 08:12 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

struct LazySeg {
    // range add and range max
    int n;
    V<ll> tree, lzAdd, l, r;
    LazySeg(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, 0);
        lzAdd.assign(2 * n, 0);
        l.resize(2 * n);
        r.resize(2 * n);
        for (int i = 2 * n - 1; i >= 1; i--) {
            if (i >= n) {
                l[i] = i - n;
                r[i] = i - n;
            } else {
                l[i] = l[2 * i];
                r[i] = r[2 * i + 1];
            }
        }
    }
    void push(int i) {
        if (i < n) {
            lzAdd[2 * i] += lzAdd[i];
            lzAdd[2 * i + 1] += lzAdd[i];
        }
        tree[i] += lzAdd[i];
        lzAdd[i] = 0;
    }
    void pull(int i) {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    void range_add(int node, int ll, int rr, int v) {
        push(node);
        if (rr < l[node] || r[node] < ll)
            return;
        if (ll <= l[node] && r[node] <= rr) {
            lzAdd[node] += v;
            push(node);
        } else {
            range_add(2 * node, ll, rr, v);
            range_add(2 * node + 1, ll, rr, v);
            pull(node);
        }
    }
    void range_add(int ll, int rr, int v) {
        range_add(1, ll, rr, v);
    }
    int range_qry(int node, int ll, int rr) {
        push(node);
        if (rr < l[node] || r[node] < ll)
            return -2 * INF;
        if (ll <= l[node] && r[node] <= rr)
            return tree[node];
        return max(range_qry(2 * node, ll, rr), range_qry(2 * node + 1, ll, rr));
    }
    int range_qry(int ll, int rr) {
        return range_qry(1, ll, rr);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<V<int>> children(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        children[p].push_back(i);
    }
    V<int> competence(n);
    for (int& i : competence)
        cin >> i;
    // idea: boils down to point updates and max subtree sum queries
    // if we store the subtree sum in each node, it's path updates and max qry
    // which can be done with HLD and lazy segtree
    V<int> subtree_sz(n, 1);
    auto calc_subtree_size = [&](auto&& self, int x) -> void {
        for (int i : children[x]) {
            self(self, i);
            subtree_sz[x] += subtree_sz[i];
        }
    };
    calc_subtree_size(calc_subtree_size, 0);
    V<int> par(n), hld_par(n), hld_pos(n);
    int cur = 0;
    auto dfs = [&](auto&& self, int x) -> void {
        hld_pos[x] = cur++;
        int heaviest = -1;
        for (int i : children[x]) {
            par[i] = x;
            if (heaviest == -1 || subtree_sz[i] > subtree_sz[heaviest])
                heaviest = i;
        }
        if (heaviest == -1)
            return;
        hld_par[heaviest] = hld_par[x];
        self(self, heaviest);
        for (int i : children[x]) {
            if (i != heaviest) {
                hld_par[i] = i;
                self(self, i);
            }
        }
    };
    hld_par[0] = 0;
    par[0] = -1;
    dfs(dfs, 0);
    // start actually doing the stuff
    LazySeg lzseg(n);
    V<int> ans(n);
    cur = 0;
    priority_queue<array<int, 2>> pq;
    pq.push({competence[0], 0});
    while (!empty(pq)) {
        int nxt = pq.top()[1];
        pq.pop();
        for (int i : children[nxt])
            pq.push({competence[i], i});
        // add -INF to path
        for (int i = nxt; i != -1; i = par[hld_par[i]])
            lzseg.range_add(hld_pos[hld_par[i]], hld_pos[i], -INF);
        ans[nxt] = cur - max(lzseg.range_qry(0, n - 1), 0);
        // add INF + 1 to path
        for (int i = nxt; i != -1; i = par[hld_par[i]])
            lzseg.range_add(hld_pos[hld_par[i]], hld_pos[i], INF + 1);
        cur++;
    }
    while (q--) {
        int v; cin >> v; v--;
        cout << ans[v] << ' ';
    }
    cout << '\n';
    return 0;
}
