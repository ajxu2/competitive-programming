#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n; i++) {
        bool encountered = false;
        for (int j = 0; j < n; j++) {
            int tmp; cin >> tmp;
            if (tmp == i+1) encountered = true;
            if (!encountered) adj[i+1].push_back(tmp);
        }
    }
    // cool now we have an edgelist
    // find cycles starting from node i
    set<array<int, 2>> cycles;
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n+1, false);
        queue<array<int, 2>> q; // node, parent
        q.push({i, 0});
        while (!q.empty()) {
            array<int, 2> process = q.front();
            q.pop();
            if (process[0] == i && process[1] != 0) {
                // cycle found
                cycles.insert(process);
            }
            if (visited[process[0]]) continue;
            visited[process[0]] = true;
            for (int j : adj[process[0]]) {
                q.push({j, process[0]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j : adj[i]) {
            // can cow i receive this gift?
            if (cycles.count({j, i})) {
                cout << j << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << i << "\n";
    }
    return 0;
}
