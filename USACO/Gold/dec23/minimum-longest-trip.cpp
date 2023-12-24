#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct State {
    int len, ptr, w; ll ans; V<int> lift;
    State(int len, int ptr, int w, ll ans, V<int> lift) : len(len), ptr(ptr), w(w), ans(ans), lift(lift) {}
    State() {}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> adj(n, V<array<int, 2>>());
    V<int> in(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v, l; cin >> u >> v >> l; u--, v--;
        adj[u].push_back({v, l});
        in[v]++;
    }
    // toposort
    queue<int> q;
    for (int i = 0; i < n; i++) if (in[i] == 0) q.push(i);
    V<int> topo;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        topo.push_back(p);
        for (array<int, 2> i : adj[p]) {
            in[i[0]]--;
            if (in[i[0]] == 0) q.push(i[0]);
        }
    }
    reverse(begin(topo), end(topo));
    V<State> dp(n, State(0, -1, 0, 0, V<int>(20, -1)));
    auto cmp = [&](int x, int y) {
        // compares the two sequences starting at x and y, assuming equal in length; returns 1 if x < y
        for (int i = 19; i >= 0; i--) {
            if (dp[x].lift[i] == -1) continue;
            ll sumx = dp[x].ans - dp[dp[x].lift[i]].ans;
            ll sumy = dp[y].ans - dp[dp[y].lift[i]].ans;
            if (sumx == sumy) {
                x = dp[x].lift[i];
                y = dp[y].lift[i];
            }
        }
        if (x == -1 || y == -1) return false;
        return dp[x].w < dp[y].w;
        return false;
    };
    for (int i : topo) {
        for (array<int, 2> j : adj[i]) {
            int nxt = j[0], w = j[1];
            if (dp[nxt].len + 1 > dp[i].len || (dp[nxt].len + 1 == dp[i].len && (w < dp[i].w || w == dp[i].w && cmp(nxt, dp[i].ptr)))) {
                dp[i].len = dp[nxt].len + 1;
                dp[i].ptr = nxt;
                dp[i].w = w;
                dp[i].ans = dp[nxt].ans + w;
                dp[i].lift[0] = dp[i].ptr;
                for (int j = 1; j < 20; j++) {
                    if (dp[i].lift[j-1] == -1) dp[i].lift[j] = -1;
                    else dp[i].lift[j] = dp[dp[i].lift[j-1]].lift[j-1];
                }
            }
        }
    }
    for (State i : dp) cout << i.len << " " << i.ans << "\n";
    return 0;
}
