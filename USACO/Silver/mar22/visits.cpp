#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<array<int, 2>> a(n+1);
    vector<vector<int>> adj(n+1);
    long long theSum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        adj[i].push_back(a[i][0]);
        adj[a[i][0]].push_back(i);
        theSum += a[i][1];
    }
    // detect the starts of the CCs
    vector<bool> visited(n+1, false);
    vector<int> starts;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        starts.push_back(i);
        queue<int> q;
        q.push(i); visited[i] = true;
        while (!q.empty()) {
            int process = q.front();
            q.pop();
            for (int j : adj[process]) {
                if (!visited[j]) {
                    q.push(j); visited[j] = true;
                }
            }
        }
    }
    // Floyd's algorithm !!!
    for (int i : starts) {
        int t = i, h = i;
        do {
            t = a[t][0];
            h = a[h][0]; h = a[h][0];
        } while (t != h);
        int orig = t, minEdge = 2e9;
        do {
            minEdge = min(minEdge, a[t][1]);
            t = a[t][0];
        } while (t != orig);
        theSum -= minEdge;
    }
    cout << theSum << "\n";
    return 0;
}
