// created: 06-23-2024 Sun 09:53 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const array<int, 4> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> a(n, V<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny)) mx = max(mx, a[nx][ny]);
            }
            if (a[i][j] > mx) a[i][j] = mx;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m-1];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
