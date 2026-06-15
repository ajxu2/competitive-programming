// created: 06-13-2026 Sat 09:38 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int b; cin >> b; b--;
            adj[b].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ssize(adj[i]) << ' ';
        for (int j : adj[i])
            cout << j + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
