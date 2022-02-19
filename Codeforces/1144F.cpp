// created: 02-19-2022 Sat 02:06 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    map<array<int, 2>, int> lookup; // (edge, edge #)
    // edge # negative if going other way
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        lookup[{a, b}] = (i+1);
        lookup[{b, a}] = -(i+1);
    }
    // key observation: all nodes must have all ingoing or all outgoing
    vector<int> visited(n+1, 0); // 0 for unvisited, 1 for in, -1 for out
    visited[1] = -1;
    // run BFS to set in/out
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int process = q.front();
        q.pop();
        for (int i : adj[process]) {
            if (visited[i] == 0) {
                visited[i] = -(visited[process]);
                q.push(i);
            }
        }
    }
    // does this construction work?
    vector<int> ans(m+1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            array<int, 2> edge;
            if (visited[i] == -1) edge = {i, j};
            else edge = {j, i};
            int tmp = lookup[edge];
            if (tmp < 0) {
                if (ans[-tmp] == 0) {
                    // collision
                    cout << "NO\n";
                    return 0;
                } else ans[-tmp] = 1;
            } else {
                if (ans[tmp] == 1) {
                    // collision
                    cout << "NO\n";
                    return 0;
                } else ans[tmp] = 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++) cout << ans[i];
    cout << "\n";
    return 0;
}
