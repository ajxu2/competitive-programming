// created: 12-22-2024 Sun 02:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> a(n);
    int max_l = 0;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        a[i].resize(l);
        for (int j = 0; j < l; j++) cin >> a[i][j];
        max_l = max(max_l, l);
    }
    // make some dag idk
    V<V<int>> adj(max_l + 2);
    for (int i = 0; i < n; i++) {
        sort(begin(a[i]), end(a[i]));
        int l = ssize(a[i]);
        // find first and second mex
        V<int> excluded;
        int ptr = 0;
        for (int j = 0; j < l + 2; j++) {
            while (ptr < l && a[i][ptr] < j) ptr++;
            if (ptr == l || a[i][ptr] != j) excluded.push_back(j);
        }
        adj[excluded[0]].push_back(excluded[1]);
    }
    // dp on the greatest number you can get to on the dag
    V<int> ans(max_l + 2);
    iota(begin(ans), end(ans), 0);
    int max_reachable = -1;
    for (int i = max_l + 1; i >= 0; i--) {
        for (int j : adj[i]) {
            ans[i] = max(ans[i], ans[j]);
        }
        if (ssize(adj[i]) >= 1) max_reachable = max(max_reachable, i);
        if (ssize(adj[i]) >= 2) max_reachable = max(max_reachable, ans[i]);
    }
    for (int i = 0; i < max_l + 2; i++) {
        ans[i] = max(ans[i], max_reachable);
    }
    if (ssize(ans) >= m + 1) {
        cout << accumulate(begin(ans), begin(ans) + m + 1, 0LL) << '\n';
    } else {
        cout << accumulate(begin(ans), end(ans), 0LL) + (ll)(m + 1 - ssize(ans)) * (ssize(ans) + m) / 2 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
