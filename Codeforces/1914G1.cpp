// created: 11-24-2024 Sun 02:24 AM

// dustin orz
#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998'244'353;

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(2*n);
    std::vector<int> l(n, -1), r(n, -1);
    for (int i = 0; i < 2*n; i++) {
        std::cin >> a[i]; a[i]--;
        if (l[a[i]] == -1) l[a[i]] = i;
        else r[a[i]] = i;
    }
    std::vector<std::vector<int>> adj(n), radj(n);
    for (int i = 0; i < n; i++) {
        std::vector<bool> on(n, false);
        for (int j = l[i] + 1; j < r[i]; j++) on[a[j]] = true;
        for (int j = 0; j < n; j++) if (on[j]) {
            adj[i].push_back(j); radj[j].push_back(i);
        }
    }
    // decompose into SCCs
    std::vector<bool> vis(n, false);
    std::vector<int> topo;
    auto dfs1 = [&](auto&& self, int x) -> void {
        vis[x] = true;
        for (int i : adj[x]) {
            if (!vis[i]) self(self, i);
        }
        topo.push_back(x);
    };
    for (int i = 0; i < n; i++) if (!vis[i]) dfs1(dfs1, i);
    std::reverse(std::begin(topo), std::end(topo));
    std::vector<int> scc_ids(n);
    int num_scc = 0;
    vis.assign(n, false);
    auto dfs2 = [&](auto&& self, int x) -> void {
        vis[x] = true; scc_ids[x] = num_scc;
        for (int i : radj[x]) {
            if (!vis[i]) self(self, i);
        }
    };
    for (int i : topo) {
        if (!vis[i]) {
            dfs2(dfs2, i);
            num_scc++;
        }
    }
    std::vector<bool> indeg0(num_scc, true);
    std::vector<int> scc_size(num_scc, 0);
    for (int i = 0; i < n; i++) {
        scc_size[scc_ids[i]]++;
        for (int j : radj[i]) {
            if (scc_ids[i] != scc_ids[j]) indeg0[scc_ids[i]] = false;
        }
    }
    int ans1 = 0; long long ans2 = 1;
    for (int i = 0; i < num_scc; i++) {
        if (indeg0[i]) {
            ans1++; ans2 = ans2 * 2 * scc_size[i] % MOD;
        }
    }
    std::cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
