#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edgelist;
vector<int> visited;
int numVisited = 0;

void dfs(int node) {
    visited[node] = true;
    numVisited++;
    for (auto& i : edgelist[node]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    edgelist.resize(n+1);
    visited.resize(n+1);
    vector<array<int, 3>> coords(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> coords[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            int dist = (coords[i][0]-coords[j][0])*(coords[i][0]-coords[j][0])+(coords[i][1]-coords[j][1])*(coords[i][1]-coords[j][1]);
            if (coords[i][2]*coords[i][2] >= dist) {
                edgelist[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        numVisited = 0;
        for (int j = 1; j <= n; j++) {
            visited[j] = false;
        }
        dfs(i);
        ans = max(ans, numVisited);
    }
    cout << ans << "\n";
    return 0;
}
