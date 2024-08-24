// created: 08-22-2024 Thu 11:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) { cin >> i; i--; }
    V<V<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[i].push_back(a[i]); adj[a[i]].push_back(i);
    }
    // find cycle nodes
    V<bool> cycle(n, false), vis(n, false);
    auto mark_as_done = [&](auto&& self, int x) -> void {
        vis[x] = true;
        for (int i : adj[x]) {
            if (vis[i]) continue;
            self(self, i);
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int tortoise = i, hare = i;
        do {
            tortoise = a[tortoise];
            hare = a[a[hare]];
        } while (tortoise != hare);
        do {
            cycle[hare] = true;
            hare = a[hare];
        } while (tortoise != hare);
        mark_as_done(mark_as_done, i);
    }
    V<bool> uncircled(n, true);
    auto dfs = [&](auto&& self, int x, int p) -> void {
        for (int i : adj[x]) {
            if (i == p || cycle[i]) continue;
            self(self, i, x);
            if (uncircled[i]) uncircled[x] = false;
        }
    };
    for (int i = 0; i < n; i++) if (cycle[i]) dfs(dfs, i, -1);
    for (int i = 0; i < n; i++) {
        if (!cycle[i]) continue;
        // check if cycle is all uncircled
        int len = 0; bool all_uncircled = true;
        int hare = i;
        do {
            len++; all_uncircled &= uncircled[hare];
            hare = a[hare];
        } while (hare != i);
        if (all_uncircled && len % 2 == 1) {
            cout << "-1\n";
            return 0;
        }
        // mark cycle as done
        int tortoise = i;
        if (!all_uncircled) while (uncircled[tortoise]) tortoise = a[tortoise];
        hare = tortoise;
        do {
            if (uncircled[hare]) uncircled[a[hare]] = false;
            cycle[hare] = false;
            hare = a[hare];
        } while (hare != tortoise);
    }
    V<int> ans;
    for (int i = 0; i < n; i++) if (uncircled[i]) ans.push_back(a[i]);
    cout << ssize(ans) << '\n';
    for (int i = 0; i < ssize(ans); i++) cout << ans[i] + 1 << " \n"[i == ssize(ans) - 1];
    return 0;
}
