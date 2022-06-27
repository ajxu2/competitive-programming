// created: 06-27-2022 Mon 02:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> up(n+1, vector<int>(19, -1)); // up[i][x] = 2^xth ancestor of i
    for (int i = 2; i <= n; i++) {
        int tmp; cin >> tmp;
        up[i][0] = tmp;
    }
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            if (up[j][i-1] != -1) up[j][i] = up[up[j][i-1]][i-1];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        for (int j = 0; j < 19; j++) {
            if ((k>>j)&1 && x != -1) x = up[x][j];
        }
        cout << x << "\n";
    }
    return 0;
}
