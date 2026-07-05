// created: 07-05-2026 Sun 03:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void chmax(int& a, int b) {
    if (b > a)
        a = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w, q; cin >> h >> w >> q;
    V<tuple<int, int, char>> queries(q);
    V<V<int>> grid(h, V<int>(w, -1)); // last update time
    for (int i = 0; i < q; i++) {
        int r, c; char x; cin >> r >> c >> x; r--, c--;
        queries[i] = {r, c, x};
        grid[r][c] = i;
    }
    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if (i < h - 1)
                chmax(grid[i][j], grid[i + 1][j]);
            if (j < w - 1)
                chmax(grid[i][j], grid[i][j + 1]);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == -1)
                cout << 'A';
            else
                cout << get<2>(queries[grid[i][j]]);
        }
        cout << '\n';
    }
    return 0;
}
