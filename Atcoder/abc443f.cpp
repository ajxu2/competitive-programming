// created: 02-02-2026 Mon 05:21 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // idea is to make a graph where the vertices are (last digit, mod class)
    // and the edges are like (_, x) -> (d, 10x + d)
    int n; cin >> n;
    if (n < 10) {
        cout << n << '\n';
        return 0;
    }
    V<V<array<int, 2>>> par(10, V<array<int, 2>>(n, {-1, -1}));
    queue<array<int, 2>> bfs;
    for (int i = 1; i < 10; i++) {
        par[i][i] = {i, i};
        bfs.push({i, i});
    }
    int final_digit = -1;
    while (!bfs.empty()) {
        auto [d, x] = bfs.front();
        bfs.pop();
        if (x == 0) {
            final_digit = d;
            break;
        }
        for (int nd = d; nd < 10; nd++) {
            int nx = (10 * x + nd) % n;
            if (par[nd][nx][0] == -1) {
                par[nd][nx] = {d, x};
                bfs.push({nd, nx});
            }
        }
    }
    if (final_digit == -1) {
        cout << "-1\n";
        return 0;
    }
    array<int, 2> cur = {final_digit, 0};
    string ans;
    while (cur != par[cur[0]][cur[1]]) {
        ans.push_back('0' + cur[0]);
        cur = par[cur[0]][cur[1]];
    }
    ans.push_back('0' + cur[0]);
    reverse(begin(ans), end(ans));
    cout << ans << '\n';
    return 0;
}
