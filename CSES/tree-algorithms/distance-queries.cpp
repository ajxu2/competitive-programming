// created: 06-27-2022 Mon 03:12 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> up, adj;
vector<int> d;

int jmp(int x, int k) {
    for (int i = 0; i < 19; i++) {
        if ((k>>i)&1) x = up[x][i];
    }
    return x;
}

void dfs(int v) {
    for (int i : adj[v]) {
        if (i != up[v][0]) {
            d[i] = d[v] + 1;
            up[i][0] = v;
            dfs(i);
        }
    }
}

int lca(int a, int b) {
    if (d[b] < d[a]) swap(a, b);
    b = jmp(b, d[b]-d[a]);
    if (a == b) return a;
    for (int j = 18; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j]; b = up[b][j];
        }
    }
    return up[a][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    up = vector<vector<int>>(n+1, vector<int>(19, 1));
    adj = vector<vector<int>>(n+1);
    d = vector<int>(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    up[1][0] = 1;
    dfs(1);
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << d[a] + d[b] - 2 * d[lca(a, b)] << "\n";
    }
    return 0;
}
