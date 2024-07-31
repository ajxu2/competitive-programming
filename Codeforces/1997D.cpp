// created: 07-30-2024 Tue 11:29 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1e9 + 7;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        adj[i].push_back(p); adj[p].push_back(i);
    }
    V<int> mm(n);
    auto dfs = [&](auto&& self, int x, int p) -> void {
        int mn = INF;
        for (int i : adj[x]) {
            if (i == p) continue;
            self(self, i, x);
            mn = min(mn, mm[i]);
        }
        if (mn == INF) mm[x] = a[x];
        else if (a[x] > mn) mm[x] = mn;
        else mm[x] = midpoint(a[x], mn);
    };
    dfs(dfs, 0, -1);
    int ans = INF;
    for (int i : adj[0]) ans = min(ans, mm[i]);
    ans += a[0];
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
