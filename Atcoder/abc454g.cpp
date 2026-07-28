// created: 04-18-2026 Sat 09:18 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, seed, m, f; cin >> n >> seed >> m >> f;
    V<int> q(m + 1), d(m + 1);
    for (int i = 2; i <= m; i++)
        cin >> q[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i];
    V<int> p(n + 1), c(n + 1);
    ll state = seed;
    for (int i = 2; i <= n; i++) {
        if (i <= m) {
            p[i] = q[i];
        } else {
            p[i] = state % (i - 1) + 1;
            state = (state * 1103515245 + 12345) & ((1LL << 31) - 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i <= m) {
            c[i] = d[i];
        } else {
            c[i] = state % f + 1;
            state = (state * 1103515245 + 12345) & ((1LL << 31) - 1);
        }
    }
    V<V<int>> children(n + 1);
    for (int i = 2; i <= n; i++)
        children[p[i]].push_back(i);
    // dsu on tree (why is it called dsu on tree tho i'll call it "sack trick")
    for (int i = 1; i <= n; i++)
        c[i]--;
    V<int> subtree_size(n + 1, 1);
    for (int i = n; i >= 1; i--)
        for (int j : children[i])
             subtree_size[i] += subtree_size[j];
    V<int> freq(n, 0);
    int max_f = 0, mult = n;
    V<int> tour, st(n + 1), en(n + 1);
    ll ans = 0;
    auto add_vertex = [&](int u) -> void {
        freq[c[u]]++;
        if (freq[c[u]] > max_f) {
            max_f = freq[c[u]];
            mult = 1;
        } else if (freq[c[u]] == max_f) {
            mult++;
        }
    };
    auto dfs = [&](this auto self, int u, bool keep) -> void {
        st[u] = ssize(tour);
        tour.push_back(u);
        int old_max_f = max_f, old_mult = mult;
        int big_child = -1, big_child_size = -1;
        for (int v : children[u]) {
            if (subtree_size[v] > big_child_size) {
                big_child = v;
                big_child_size = subtree_size[v];
            }
        }
        for (int v : children[u])
            if (v != big_child)
                self(v, false);
        if (big_child != -1)
            self(big_child, true);
        en[u] = ssize(tour);
        for (int v : children[u])
            if (v != big_child)
                for (int i = st[v]; i < en[v]; i++)
                    add_vertex(tour[i]);
        add_vertex(u);
        (ans += (ll)(max_f ^ u) * (mult ^ u)) %= MOD;
        if (!keep) {
            for (int i = st[u]; i < en[u]; i++)
                freq[c[tour[i]]]--;
            max_f = old_max_f;
            mult = old_mult;
        }
    };
    dfs(1, false);
    cout << ans << '\n';
    return 0;
}
