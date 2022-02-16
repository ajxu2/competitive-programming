// created: 02-16-2022 Wed 10:54 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // (desired topic number, blog number)
    vector<array<int, 2>> t(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        t[i][0] = tmp;
        t[i][1] = i+1;
    }
    // optimal ordering
    sort(t.begin(), t.end());
    // bor does this ordering work???
    vector<int> actTopics(n+1, -1);
    for (int i = 0; i < n; i++) {
        int node = t[i][1];
        // find actual topic number
        vector<int> tmp;
        for (int j = 0; j < adj[node].size(); j++) {
            // get all the nodes that exist next to this one
            if (actTopics[adj[node][j]] != -1) {
                tmp.push_back(actTopics[adj[node][j]]);
            }
        }
        if (tmp.empty()) actTopics[node] = 1;
        else {
            // get mex
            tmp.push_back(0);
            sort(tmp.begin(), tmp.end());
            int mex = tmp.back() + 1;
            for (int i = 0; i < (int)(tmp.size()-1); i++) {
                if (tmp[i+1] - tmp[i] > 1) {
                    mex = tmp[i] + 1;
                    break;
                }
            }
            actTopics[node] = mex;
        }
    }
    int works = true;
    for (int i = 0; i < n; i++) {
        if (t[i][0] != actTopics[t[i][1]]) works = false;
    }
    if (works) {
        for (int i = 0; i < n; i++) cout << t[i][1] << " \n"[i == n-1];
    } else cout << "-1\n";
    return 0;
}
