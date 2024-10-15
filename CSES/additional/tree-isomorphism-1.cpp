// created: 10-15-2024 Tue 02:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

uint64_t splitmix64(uint64_t x) {
    uint64_t z = x + 0x9e3779b97f4a7c15;
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
    return z ^ (z >> 31);
}

void solve() {
    int n; cin >> n;
    V<V<int>> adj1(n), adj2(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj1[u].push_back(v); adj1[v].push_back(u);
    }
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj2[u].push_back(v); adj2[v].push_back(u);
    }
    uint64_t start = chrono::steady_clock::now().time_since_epoch().count();
    cout << start << '\n';
    auto get_hash = [&](auto&& self, const V<V<int>>& adj, int x, int p) -> uint64_t {
        uint64_t sum = start;
        for (int i : adj[x]) {
            if (i != p) sum += self(self, adj, i, x);
        }
        return splitmix64(sum);
    };
    if (get_hash(get_hash, adj1, 0, -1) == get_hash(get_hash, adj2, 0, -1)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
