// created: 07-06-2024 Sat 11:58 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, q; cin >> n >> q;
    V<int> initial;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (tmp == 1) initial.push_back(i);
    }
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    V<int> par(n);
    auto dfs = [&](auto&& self, int x, int p) -> void {
        par[x] = p;
        for (int i : adj[x]) {
            if (i == p) continue;
            self(self, i, x);
        }
    };
    dfs(dfs, 0, -1);
    // we maintain:
    // 1. for each node, the number of black children
    // 2. the frequency array of the above
    // 3. the number of connected components of black nodes
    // 4. the nodes with exactly 2 black children
    V<bool> c(n, false);
    V<int> cnt(n, 0), freq(n+2, 0);
    freq[0] = n;
    int cc = 0;
    unordered_set<int> two;
    auto upd = [&](int x) -> void {
        c[x] = !c[x];
        if (c[x]) {
            if (par[x] != -1) {
                freq[cnt[par[x]]]--;
                if (cnt[par[x]] == 2) two.erase(par[x]);
                cnt[par[x]]++;
                freq[cnt[par[x]]]++;
                if (cnt[par[x]] == 2) two.insert(par[x]);
            }
            int neighbors = cnt[x];
            if (par[x] != -1 && c[par[x]]) neighbors++;
            cc -= neighbors; cc++;
        } else {
            if (par[x] != -1) {
                freq[cnt[par[x]]]--;
                if (cnt[par[x]] == 2) two.erase(par[x]);
                cnt[par[x]]--;
                freq[cnt[par[x]]]++;
                if (cnt[par[x]] == 2) two.insert(par[x]);
            }
            int neighbors = cnt[x];
            if (par[x] != -1 && c[par[x]]) neighbors++;
            cc += neighbors; cc--;
        }
    };
    auto check = [&]() -> bool {
        return cc == 1
            && freq[0] + freq[1] + freq[2] == n
            && (empty(two) || (ssize(two) == 1 && (par[*begin(two)] == -1 || !c[par[*begin(two)]])));
    };
    for (int i : initial) upd(i);
    while (q--) {
        int tmp; cin >> tmp; tmp--;
        upd(tmp);
        cout << (check() ? "Yes" : "No") << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
