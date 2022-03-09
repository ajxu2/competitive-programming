// created: 03-08-2022 Tue 11:32 PM

#include <bits/stdc++.h>
using namespace std;

// oops this code is messy

int main() {
#ifndef LOCAL
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
#endif
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<bool> type(n+1); // false for G, true for H
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') type[i+1] = false;
        else type[i+1] = true;
    }
    vector<vector<int>> gadj(n+1), hadj(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        if (type[a] && type[b]) {
            hadj[a].push_back(b);
            hadj[b].push_back(a);
        } else if (!type[a] && !type[b]) {
            gadj[a].push_back(b);
            gadj[b].push_back(a);
        }
    }
    // run BFS to determine CCs
    vector<int> gcc(n+1), hcc(n+1);
    vector<bool> visited(n+1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (visited[i]) continue;
        queue<int> q;
        q.push(i); visited[i] = true; gcc[i] = cnt;
        while (!q.empty()) {
            int process = q.front();
            q.pop();
            for (int j : gadj[process]) {
                if (!visited[j]) {
                    q.push(j); visited[j] = true; gcc[j] = cnt;
                }
            }
        }
    }
    fill(visited.begin(), visited.end(), false);
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (visited[i]) continue;
        queue<int> q;
        q.push(i); visited[i] = true; hcc[i] = cnt;
        while (!q.empty()) {
            int process = q.front();
            q.pop();
            for (int j : hadj[process]) {
                if (!visited[j]) {
                    q.push(j); visited[j] = true; hcc[j] = cnt;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'H') {
            if (a == b) cout << (int)(type[a] == true);
            else cout << (int)(gcc[a] != gcc[b]);
        } else {
            if (a == b) cout << (int)(type[a] == false);
            else cout << (int)(hcc[a] != hcc[b]);
        }
    }
    cout << "\n";
    return 0;
}
