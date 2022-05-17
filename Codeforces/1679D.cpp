// created: 05-16-2022 Mon 12:01 PM

#include <bits/stdc++.h>
using namespace std;

// Nice problem!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; long long k;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    // binary search on answer
    int l = 1, r = 1000000001;
    while (l != r) {
        int mid = (l+r)/2;
        vector<vector<int>> tadj(n+1);
        vector<vector<int>> tbadj(n+1);
        vector<int> in(n+1, 0);
        vector<bool> exist(n+1, false);
        int nodes = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= mid) {
                nodes++;
                exist[i] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!exist[i]) continue;
            for (int j : adj[i]) {
                if (!exist[j]) continue;
                tadj[i].push_back(j);
                tbadj[j].push_back(i);
                in[j]++;
            }
        }
        // find the longest path if it's a DAG
        queue<int> q;
        for (int i = 1; i <= n; i++) if (in[i] == 0 && exist[i]) q.push(i);
        vector<int> topo;
        while (!q.empty()) {
            int process = q.front();
            q.pop();
            topo.push_back(process);
            for (int i : tadj[process]) {
                in[i]--;
                if (in[i] == 0) q.push(i);
            }
        }
        bool works = false;
        if (topo.size() != nodes) works = true;
        else if (nodes == 0) works = false;
        else {
            vector<int> dp(n+1, 1);
            for (int i : topo) {
                for (int j : tbadj[i]) dp[i] = max(dp[i], dp[j]+1);
            }
            if (*max_element(dp.begin(), dp.end()) >= k) works = true;
        }
        if (works) r = mid;
        else l = mid+1;
    }
    if (l == 1000000001) cout << "-1\n";
    else cout << l << "\n";
    return 0;
}
