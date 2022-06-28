// created: 06-28-2022 Tue 09:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> st, en, a;
vector<vector<int>> adj;
int timer = 1;

void dfs(int v, int par) {
    st[v] = timer;
    for (int i : adj[v]) {
        if (i == par) continue;
        timer++;
        dfs(i, v);
    }
    en[v] = timer;
}

struct BIT {
    vector<ll> tree;
    int n;
    // construct BIT with n pieces of data
    BIT(int _n) {
        n = _n;
        tree = vector<ll>(n+1, 0);
    }
    // increase value at position i by v (1-indexed)
    void add(int i, ll v) {
        while (i <= n) {
            tree[i] += v;
            i += i & -i;
        }
    }
    // update value at position i to v (1-indexed)
    void upd(int i, ll v) {
        ll d = v - qry(i, i);
        add(i, d);
    }
    // query the sum from [1, a] (1-indexed)
    ll qry(int a) {
        ll res = 0;
        while (a > 0) {
            res += tree[a];
            a -= a & -a;
        }
        return res;
    }
    // query the sum from [a, b] (a and b are 1-indexed)
    ll qry(int a, int b) {
        return qry(b) - qry(a-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    a = vector<int>(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    st = vector<int>(n+1); en = vector<int>(n+1); adj = vector<vector<int>>(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    BIT b(n+1);
    for (int i = 1; i <= n; i++) {
        b.add(st[i], a[i]);
        b.add(en[i]+1, -a[i]);
    }
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            int d = x - a[s];
            b.add(st[s], d);
            b.add(en[s]+1, -d);
            a[s] = x;
        } else {
            int s; cin >> s;
            cout << b.qry(st[s]) << "\n";
        }
    }
    return 0;
}
