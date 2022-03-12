// created: 03-02-2022 Wed 1:31 PM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<long long>> a(n+1, vector<long long>(n+1, 1e18));
    for (int i = 1; i <= n; i++) a[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int x, y; long long w; cin >> x >> y >> w;
        a[x][y] = min(a[x][y], w); a[y][x] = min(a[y][x], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        if (a[x][y] == 1e18) cout << "-1\n";
        else cout << a[x][y] << "\n";
    }
    return 0;
}
