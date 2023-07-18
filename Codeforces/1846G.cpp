// created: 07-18-2023 Tue 01:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

const int INF = 1'000'000'000;

void solve() {
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> adj(1<<n);
    string tmp; cin >> tmp; int start = stoi(tmp, nullptr, 2);
    for (int i = 0; i < m; i++) {
        int d; cin >> d;
        cin >> tmp; int cure = stoi(tmp, nullptr, 2);
        cin >> tmp; int side = stoi(tmp, nullptr, 2);
        for (int j = 0; j < (1<<n); j++) adj[j].push_back({j & ~cure | side, d});
    }
    // ajxu2 try to implement standard algorithm challenge (99% FAIL)
    V<int> d(1<<n, INF);
    priority_queue<array<int, 2>, V<array<int, 2>>, greater<array<int, 2>>> pq;
    d[start] = 0; pq.push({0, start});
    while (!pq.empty()) {
        array<int, 2> cur = pq.top();
        pq.pop();
        if (cur[0] > d[cur[1]]) continue;
        for (array<int, 2> i : adj[cur[1]]) {
            if (cur[0] + i[1] < d[i[0]]) {
                d[i[0]] = cur[0] + i[1];
                pq.push({d[i[0]], i[0]});
            }
        }
    }
    if (d[0] == INF) cout << "-1\n";
    else cout << d[0] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
