// created: 05-13-2025 Tue 02:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;
const array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2}, dy = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<int>> d(n, V<int>(n, INF));
    queue<array<int, 2>> bfs;
    bfs.push({0, 0});
    d[0][0] = 0;
    while (!empty(bfs)) {
        auto [x, y] = bfs.front();
        bfs.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (d[nx][ny] == INF) {
                d[nx][ny] = d[x][y] + 1;
                bfs.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << d[i][j] << " \n"[j == n-1];
    return 0;
}
