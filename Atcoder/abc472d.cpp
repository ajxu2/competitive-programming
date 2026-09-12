// created: 08-22-2026 Sat 08:06 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const V<array<int, 2>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w, k; cin >> h >> w >> k;
    V<string> a(h);
    for (string& i : a)
        cin >> i;
    V<bool> row_has_bomb(h), col_has_bomb(w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                row_has_bomb[i] = true;
                col_has_bomb[j] = true;
            }
        }
    }
    auto is_valid = [&](int i, int j) -> bool {
        return 0 <= i && i < h && 0 <= j && j < w && a[i][j] == '.';
    };
    int ans = 0;
    V<V<int>> dist(h, V<int>(w, -1));
    queue<array<int, 2>> bfs;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!row_has_bomb[i] && !col_has_bomb[j]) {
                dist[i][j] = 0;
                bfs.push({i, j});
            }
        }
    }
    while (!bfs.empty()) {
        auto [i, j] = bfs.front();
        bfs.pop();
        ans++;
        if (dist[i][j] == k)
            continue;
        for (auto [dx, dy] : d) {
            if (is_valid(i + dx, j + dy) && dist[i + dx][j + dy] == -1) {
                dist[i + dx][j + dy] = dist[i][j] + 1;
                bfs.push({i + dx, j + dy});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
