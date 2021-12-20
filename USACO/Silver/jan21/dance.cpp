// created: 12-17-2021 Fri 11:17 PM

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ans;
set<int> noted;
vector<int> inCycle;
vector<set<int>> s;

void dfs(vector<int>& g, vector<bool>& visited, int node) {
    visited[node] = true;
    noted.merge(s[node]);
    inCycle.push_back(node);
    if (!visited[g[node]]) {
        dfs(g, visited, g[node]);
    }
}

int main() {
    cin >> n >> k;
    vector<array<int, 2>> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    vector<int> cows(n+1);
    for (int i = 1; i <= n; i++) {
        cows[i] = i;
    }
    s.resize(n+1);
    for (int i = 1; i <= n; i++) {
        s[i].insert(i);
    }
    for (int i = 0; i < k; i++) {
        swap(cows[a[i][0]], cows[a[i][1]]);
        s[cows[a[i][0]]].insert(a[i][0]);
        s[cows[a[i][1]]].insert(a[i][1]);
    }
    vector<int> g(n+1);
    for (int i = 1; i <= n; i++) {
        g[cows[i]] = i;
    }
    ans.resize(n+1);
    vector<bool> visited(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            noted.clear();
            inCycle.clear();
            dfs(g, visited, i);
            for (int j : inCycle) {
                ans[j] = (int)(noted.size());
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
