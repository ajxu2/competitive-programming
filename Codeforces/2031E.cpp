// created: 12-29-2024 Sun 11:43 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> using gpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        adj[p].push_back(i);
    }
    V<int> dp(n); // dp[i] = depth of binary tree for this subtree
    auto dfs = [&](auto&& self, int x) -> void {
        for (int i : adj[x]) self(self, i);
        if (ssize(adj[x]) == 0) {
            dp[x] = 0;
        } else if (ssize(adj[x]) == 1) {
            dp[x] = dp[adj[x][0]] + 1;
        } else {
            gpq<int> pq;
            for (int i : adj[x]) pq.push(dp[i]);
            while (ssize(pq) > 1) {
                int one = pq.top(); pq.pop();
                int two = pq.top(); pq.pop();
                pq.push(max(one, two) + 1);
            }
            dp[x] = pq.top();
        }
    };
    dfs(dfs, 0);
    cout << dp[0] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
