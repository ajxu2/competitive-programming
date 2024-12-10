// created: 12-10-2024 Tue 12:30 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

void solve() {
    int n, m; cin >> n >> m;
    V<V<short>> rock(n, V<short>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rock[i][j];
        }
    }
    // fix position of rocks
    // RT can stay still, move 2 down, or move down right
    // end position moving downward
    V<V<int>> dist(n, V<int>(m, INF));
    dist[0][0] = 0;
    queue<array<int, 2>> bfs;
    bfs.push({0, 0});
    while (!empty(bfs)) {
        array<int, 2> cur = bfs.front();
        int x = cur[0], y = cur[1];
        bfs.pop();
        if (!rock[(x+1)%n][y] && !rock[(x+2)%n][y] && dist[(x+2)%n][y] == INF) {
            dist[(x+2)%n][y] = dist[x][y] + 1;
            bfs.push({(x+2)%n, y});
        }
        if (y < m-1 && !rock[(x+1)%n][y+1] && dist[(x+1)%n][y+1] == INF) {
            dist[(x+1)%n][y+1] = dist[x][y] + 1;
            bfs.push({(x+1)%n, y+1});
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int d = dist[i][m-1];
        int epos = (n - 1 + d) % n;
        int catchup = min(abs(epos - i), n - abs(epos - i));
        ans = min(ans, d + catchup);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
