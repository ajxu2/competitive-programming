// created: 05-17-2022 Tue 03:24 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> in(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 1; i <= n; i++) if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int process = q.front();
        q.pop();
        topo.push_back(process);
        for (int i : adj[process]) {
            in[i]--;
            if (in[i] == 0) q.push(i);
        }
    }
    if (topo.size() != n) cout << "IMPOSSIBLE\n";
    else for (int i = 0; i < n; i++) cout << topo[i] << " \n"[i == n-1];
    return 0;
}
