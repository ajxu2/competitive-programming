#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > edgelist(n+1);
    vector<set<int> > neighbors(n+1);
    int t1, t2;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        edgelist[t1].push_back(t2);
        edgelist[t2].push_back(t1);
    }
    int ans;
    for (int i = 1; i <= n; i++) {
        if (neighbors[i].size()) {
            if (!neighbors[i].count(1)) {
                ans = 1;
            } else if (!neighbors[i].count(2)) {
                ans = 2;
            } else if (!neighbors[i].count(3)) {
                ans = 3;
            } else if (!neighbors[i].count(4)) {
                ans = 4;
            }
        } else {
            ans = 1;
        }
        for (int j = 0; j < (int)edgelist[i].size(); j++) {
            neighbors[edgelist[i][j]].insert(ans);
        }
        cout << ans;
    }
    cout << "\n";
    return 0;
}
