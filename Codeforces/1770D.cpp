// created: 12-30-2022 Fri 09:16 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998244353;

V<V<int>> adj;
V<int> cc;
V<bool> vis;
bool selfloop;

void dfs(int x) {
    vis[x] = true; cc.push_back(x);
    for (int i : adj[x]) {
        if (i == x) selfloop = true;
        else if (!vis[i]) dfs(i);
    }
}

void solve() {
    int n; cin >> n;
    adj.clear(); adj.resize(n);
    vis = V<bool>(n, false);
    V<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            ans *= n; ans %= MOD;
        }
        adj[a[i]-1].push_back(b[i]-1);
        adj[b[i]-1].push_back(a[i]-1);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        cc.clear(); selfloop = false;
        dfs(i);
        int v = cc.size(), e = 0;
        for (int j : cc) e += adj[j].size();
        e /= 2;
        if (v != e) {
            cout << "0\n";
            return;
        }
        if (!selfloop) ans *= 2; ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
