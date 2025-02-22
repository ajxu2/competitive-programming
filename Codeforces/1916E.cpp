// created: 02-21-2025 Fri 01:19 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct LazySeg {
    // lazy segment tree with range sum update, range max qry
    // also with HALF OPEN INTERVALS
    const int id = 0;
    int n;
    V<int> tree, lazy, l, r;
    LazySeg(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        tree.assign(2*n, id);
        lazy.assign(2*n, 0);
        l.resize(2*n); r.resize(2*n);
        iota(begin(l) + n, end(l), 0);
        iota(begin(r) + n, end(r), 1);
        for (int i = n-1; i >= 1; i--) {
            l[i] = l[2*i]; r[i] = r[2*i+1];
        }
    }
    void pull(int i) {
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }
    void push(int i) {
        if (i < n) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        tree[i] += lazy[i];
        lazy[i] = 0;
    }
    void upd(int ll, int rr, int x, int i) {
        push(i);
        if (rr <= l[i] || r[i] <= ll) return;
        if (ll <= l[i] && r[i] <= rr) {
            lazy[i] += x;
            push(i);
            return;
        }
        upd(ll, rr, x, 2*i); upd(ll, rr, x, 2*i+1);
        pull(i);
    }
    void upd(int ll, int rr, int x) { upd(ll, rr, x, 1); }
    int qry(int ll, int rr, int i) {
        push(i);
        if (rr <= l[i] || r[i] <= ll) return id;
        if (ll <= l[i] && r[i] <= rr) return tree[i];
        return max(qry(ll, rr, 2*i), qry(ll, rr, 2*i+1));
    }
    int qry(int ll, int rr) { return qry(ll, rr, 1); }
};

void solve() {
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        adj[i].push_back(p); adj[p].push_back(i);
    }
    V<int> a(n);
    for (int& i : a) { cin >> i; i--; }
    // generate euler tour, and also lowest ancestor with same color
    V<int> euler, st(n), en(n), lst(n, -1);
    V<V<int>> path_freq(n);
    int timer = 0;
    auto dfs1 = [&](auto&& self, int x, int p) -> void {
        euler.push_back(x);
        if (!path_freq[a[x]].empty()) lst[x] = path_freq[a[x]].back();
        path_freq[a[x]].push_back(x);
        st[x] = timer++;
        for (int i : adj[x]) {
            if (i != p) self(self, i, x);
        }
        en[x] = timer;
        path_freq[a[x]].pop_back();
    };
    dfs1(dfs1, 0, -1);
    V<V<int>> ch_same_color(n);
    for (int i = 0; i < n; i++) {
        if (lst[i] != -1) ch_same_color[lst[i]].push_back(i);
    }
    LazySeg lzseg(n);
    ll ans = 0;
    auto dfs2 = [&](auto&& self, int x, int p) -> void {
        for (int i : adj[x]) {
            if (i != p) self(self, i, x);
        }
        for (int i : ch_same_color[x]) {
            lzseg.upd(st[i], en[i], -1);
        }
        lzseg.upd(st[x], en[x], 1);
        V<int> stuff;
        for (int i : adj[x]) {
            if (i != p) stuff.push_back(lzseg.qry(st[i], en[i]));
        }
        sort(begin(stuff), end(stuff), greater<int>());
        if (ssize(stuff) > 1) ans = max(ans, (ll)stuff[0] * stuff[1]);
    };
    dfs2(dfs2, 0, -1);
    ans = max(ans, (ll)lzseg.qry(st[0], en[0]));
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
