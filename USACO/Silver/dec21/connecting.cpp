// created: 12-18-2021 Sat 02:04 PM

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
vector<set<int>> onpath;
set<int> tmp;

void dfs(int node) {
    tmp.insert(node);
    for (int i : edges[node]) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
}

long long getAns1(int diff) {
    // get minimum cost given 1 road and a difference
    return (long long)diff * diff;
}

long long getAns2(int diff) {
    // get minimum cost given 2 roads and a difference
    long long ans;
    if (diff % 2 == 0) {
        ans = (long long)diff * diff / 2;
    } else {
        ans = ((long long)diff / 2) * (diff / 2);
        ans += (((long long)diff+1) / 2) * ((diff+1) / 2);
    }
    return ans;
}

int getDist(set<int>& a, set<int>& b) {
    // for each node in a, calculate min distance to a node in b
    // O(a log b)
    int minDist = 1e9;
    for (int i : a) {
        int thisDist;
        auto it = b.lower_bound(i);
        if (it == b.end()) {
            // none higher
            thisDist = 1e9;
        } else {
            thisDist = *it - i;
        }
        if (it != b.begin()) {
            // there are lower
            it--;
            thisDist = min(thisDist, i - *it);
        }
        minDist = min(minDist, thisDist);
    }
    return minDist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    edges.clear();
    visited.clear();
    onpath.clear();
    tmp.clear();
    edges.resize(n+1);
    visited.resize(n+1);
    // construct edgelist
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // reset visited array
    for (int i = 2; i <= n; i++) {
        visited[i] = false;
    }
    // run dfs from 1 and get the array
    visited[1] = true;
    dfs(1);
    if (visited[n]) {
        // n is on the same component as 1, no roads needed
        cout << "0\n";
        return;
    }
    onpath.push_back(tmp);
    // run dfs from n
    tmp.clear();
    visited[n] = true;
    dfs(n);
    onpath.push_back(tmp);
    // run dfs from every other node
    for (int i = 2; i <= n; i++) {
        tmp.clear();
        if (!visited[i]) {
            visited[i] = true;
            dfs(i);
            onpath.push_back(tmp);
        }
    }
    long long ans = LLONG_MAX;
    // iterate through all connected components that are not 1 or n
    for (int i = 2; i < (int)onpath.size(); i++) {
        ans = min(ans, getAns1(getDist(onpath[i], onpath[0])) + getAns1(getDist(onpath[i], onpath[1])));
    }
    // alternatively, build two roads without any connected components in the middle
    ans = min(ans, getAns2(getDist(onpath[0], onpath[1])));
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
