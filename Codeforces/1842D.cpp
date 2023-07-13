// created: 07-02-2023 Sun 03:52 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

const ll INF = 1'000'000'000'000'000'000;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<ll>> adj(n, V<ll>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, d; cin >> u >> v >> d; u--, v--;
        adj[u][v] = d; adj[v][u] = d;
    }
    V<bool> vis(n, 0);
    V<pair<string, int>> ans;
    vis[0] = 1;
    for (int i = 0; i < n-1; i++) {
        // get edges connected to only 1 vis
        int mnj, mnk; ll mn = INF;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (vis[j] && !vis[k] && adj[j][k] < mn) {
                    mnj = j; mnk = k; mn = adj[j][k];
                }
            }
        }
        if (mn > INF/2) {
            cout << "inf\n";
            return 0;
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (vis[j] && !vis[k]) {
                    adj[j][k] -= mn; adj[k][j] -= mn;
                }
            }
        }
        string s(n, '0');
        for (int j = 0; j < n; j++) if (vis[j]) s[j] = '1';
        ans.push_back({s, mn});
        if (mnk == n-1) break;
        vis[mnk] = 1;
    }
    ll tot = 0;
    for (pair<string, int> i : ans) tot += i.second;
    cout << tot << " " << sz(ans) << "\n";
    for (pair<string, int> i : ans) cout << i.first << " " << i.second << "\n";
    return 0;
}
