// created: 06-27-2022 Mon 02:54 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> up; // up[i][x] = 2^xth ancestor of i
vector<vector<int>> adj;
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
            dfs(i);
        }
    }
}

int main() {
    int n, q; cin >> n >> q;
    up = vector<vector<int>>(n+1, vector<int>(19, 1));
    adj = vector<vector<int>>(n+1);
    d = vector<int>(n+1, 0);
    for (int i = 2; i <= n; i++) {
        int tmp; cin >> tmp;
        adj[i].push_back(tmp); adj[tmp].push_back(i);
        up[i][0] = tmp;
    }
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }
    dfs(1);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (d[b] < d[a]) swap(a, b);
        b = jmp(b, d[b]-d[a]);
        if (a == b) {
            cout << a << "\n"; continue;
        }
        for (int j = 18; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j]; b = up[b][j];
            }
        }
        cout << up[a][0] << "\n";
    }
    return 0;
}
