// created: 03-03-2022 Thu 10:03 PM

#include <bits/stdc++.h>
using namespace std;

// basically copied from https://cses.fi/book/book.pdf#page=62

vector<vector<bool>> vis(9, vector<bool>(9, false));
vector<int> given(48);
vector<string> paths;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int search(int depth, int x, int y) {
    // optimizations 2, 3 & 4
    if (x == 1 && y == 1) {
        if (depth == 48) return 1;
        return 0;
    }
    if (!vis[x-1][y] && !vis[x+1][y] && vis[x][y-1] && vis[x][y+1]) return 0;
    if (!vis[x][y-1] && !vis[x][y+1] && vis[x-1][y] && vis[x+1][y]) return 0;
    vis[x][y] = true;
    int res = 0;
    if (given[depth] < 4) {
        x += dx[given[depth]], y += dy[given[depth]];
        if (!vis[x][y]) res = search(depth+1, x, y);
        x -= dx[given[depth]], y -= dy[given[depth]];
    }
    else {
        for (int i = 0; i < 4; i++) {
            x += dx[i], y += dy[i];
            if (!vis[x][y]) res += search(depth+1, x, y);
            x -= dx[i], y -= dy[i];
        }
    }
    vis[x][y] = false;
    return res;
}

int main() {
    for (int i = 0; i < 9; i++) {
        vis[0][i] = true;
        vis[i][0] = true;
        vis[8][i] = true;
        vis[i][8] = true;
    }
    string s; cin >> s;
    for (int i = 0; i < 48; i++) {
        if (s[i] == 'R') given[i] = 0;
        else if (s[i] == 'U') given[i] = 1;
        else if (s[i] == 'L') given[i] = 2;
        else if (s[i] == 'D') given[i] = 3;
        else given[i] = 4;
    }
    cout << search(0, 1, 7) << "\n";
    return 0;
}
