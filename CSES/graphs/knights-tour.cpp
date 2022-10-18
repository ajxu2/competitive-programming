// created: 10-18-2022 Tue 12:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> a;
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool possible(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8 && a[x][y] == 0;
}

int main() {
    // just CPH p. 110, how is this a graph problem?
    int x, y; cin >> x >> y;
    a = vector<vector<int>>(9, vector<int>(9, 0));
    a[x][y] = 1;
    for (int i = 2; i <= 64; i++) {
        int nx = 0, ny = 0, m = 9;
        for (int j = 0; j < 8; j++) {
            int tx = x+dx[j], ty = y+dy[j];
            if (possible(tx, ty)) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) if (possible(tx+dx[k], ty+dy[k])) cnt++;
                if (cnt < m) {
                    nx = tx, ny = ty, m = cnt;
                }
            }
        }
        a[nx][ny] = i;
        x = nx, y = ny;
    }
    for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) cout << a[j][i] << " \n"[j == 8];
    return 0;
}
