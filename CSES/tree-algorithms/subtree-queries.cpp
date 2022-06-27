#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
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
 
vector<int> st, en;
vector<vector<int>> adj;
int timer = 1;
 
void dfs(int node, int par) {
    st[node] = timer;
    for (int i : adj[node]) {
        if (i == par) continue;
        timer++;
        dfs(i, node);
    }
    en[node] = timer;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    st = vector<int>(n+1, 0); en = vector<int>(n+1, 0);
    adj.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    BIT b(n);
    dfs(1, 0);
    for (int i = 1; i <= n; i++) b.upd(st[i], a[i]);
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            b.upd(st[s], x);
        }
        else {
            int tmp; cin >> tmp;
            cout << b.qry(st[tmp], en[tmp]) << "\n";
        }
    }
    return 0;
}
