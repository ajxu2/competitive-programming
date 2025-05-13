// created: 10-18-2022 Tue 12:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> a;
const array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2}, dy = {1, 2, 2, 1, -1, -2, -2, -1};
bool found = false;

bool possible(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 && a[x][y] == 0;
}

int num_possibilities(array<int, 2> a) {
    int cnt = 0;
    for (int i = 0; i < 8; i++)
        if (possible(a[0] + dx[i], a[1] + dy[i]))
            cnt++;
    return cnt;
}

void backtrack(int x, int y) {
    if (a[x][y] == 64) {
        found = true;
        return;
    }
    vector<array<int, 2>> nxt;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (possible(nx, ny))
            nxt.push_back({nx, ny});
    }
    sort(begin(nxt), end(nxt), [](array<int, 2> a, array<int, 2> b) {
        return num_possibilities(a) < num_possibilities(b);
    });
    for (auto [nx, ny] : nxt) {
        a[nx][ny] = a[x][y] + 1;
        backtrack(nx, ny);
        if (found)
            return;
        a[nx][ny] = 0;
    }
}

int main() {
    // just CPH p. 110, how is this a graph problem?
    // UPDATED ON 05/13/2025 because my sol got hacked :(
    int x, y; cin >> y >> x; x--, y--;
    a = vector<vector<int>>(8, vector<int>(8, 0));
    a[x][y] = 1;
    backtrack(x, y);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cout << a[i][j] << " \n"[j == 7];
    return 0;
}
