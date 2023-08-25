// created: 08-23-2023 Wed 09:23 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        adj[i].push_back(u); adj[u].push_back(i);
    }
    V<int> subt(n, 1);
    ll ans = 0;
    function<void(int, int)> dfs = [&](int x, int p) {
        bitset<5001> k;
        k[0] = 1;
        for (int i : adj[x]) {
            if (i == p) continue;
            dfs(i, x);
            subt[x] += subt[i];
            k |= (k << subt[i]);
        }
        ll mx = 0;
        for (int i = 0; i < subt[x]; i++) {
            if (!k[i]) continue;
            mx = max(mx, (ll)i * (subt[x] - 1 - i));
        }
        ans += mx;
    };
    dfs(0, -1);
    cout << ans << "\n";
    return 0;
}
