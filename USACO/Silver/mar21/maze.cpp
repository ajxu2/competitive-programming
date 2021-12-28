// created: 12-27-2021 Mon 04:36 PM

#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Cell {
    // describes a cell in the maze
    int x, y; // describes position in maze
    char letter; // M, O, #, or .
    int n = -1; // describes position on board (-1 if not a move)
    // 0 1 2
    // 3 4 5
    // 6 7 8
};

int getNum(array<int, 9> a) {
    // get the representative number given board state
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        ans *= 3;
        ans += a[i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<Cell>> a(n, vector<Cell>(n));
    array<int, 2> starting;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            // build the maze
            string tmp = s.substr(3*j, 3);
            a[i][j].x = i;
            a[i][j].y = j;
            if (tmp[0] == 'B') {
                starting = {i, j};
                a[i][j].letter = '.';
            } else if (tmp[0] == 'M' || tmp[0] == 'O') {
                a[i][j].letter = tmp[0];
                a[i][j].n = 3*(tmp[1]-49)+tmp[2]-49;
            } else {
                a[i][j].letter = tmp[0];
            }
        }
    }
    // run iterative BFS over the maze
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(19683, false))); // 3D array - x, y, board state
    queue<array<int, 11>> q;
    // x, y, 9 numbers representing board state
    // 0 = blank, 1 = M, 2 = O
    set<int> configs; // winning configurations
    int ans = 0;
    q.push({starting[0], starting[1], 0, 0, 0, 0, 0, 0, 0, 0, 0});
    visited[starting[0]][starting[1]][0] = true;
    while (!q.empty()) {
        array<int, 11> process = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Cell j = a[process[0]+dx[i]][process[1]+dy[i]];
            array<int, 11> toAdd = process;
            // create the next node
            if (j.letter == 'M') {
                // ONLY REPLACE IF THE CELL IS BLANK (I AM STUPID)
                if (toAdd[j.n+2] == 0) toAdd[j.n+2] = 1;
            } else if (j.letter == 'O') {
                if (toAdd[j.n+2] == 0) toAdd[j.n+2] = 2;
            } else if (j.letter == '#') {
                continue; // don't process walls
            }
            toAdd[0] = j.x;
            toAdd[1] = j.y;
            // has this node been visited?
            array<int, 9> checking;
            for (int i = 2; i < 11; i++) {
                checking[i-2] = toAdd[i];
            }
            if (visited[toAdd[0]][toAdd[1]][getNum(checking)]) continue;
            visited[toAdd[0]][toAdd[1]][getNum(checking)] = true;
            // is this node a win?
            bool win = false;
            array<int, 3> win1 = {1, 2, 2}, win2 = {2, 2, 1};
            // check rows
            for (int i = 0; i < 9; i += 3) {
                array<int, 3> row = {checking[i], checking[i+1], checking[i+2]};
                if (row == win1 || row == win2) {
                    win = true;
                }
            }
            // check columns
            for (int i = 0; i < 3; i++) {
                array<int, 3> col = {checking[i], checking[i+3], checking[i+6]};
                if (col == win1 || col == win2) {
                    win = true;
                }
            }
            // check diagonals
            array<int, 3> diag = {checking[0], checking[4], checking[8]};
            if (diag == win1 || diag == win2) {
                win = true;
            }
            diag = {checking[2], checking[4], checking[6]};
            if (diag == win1 || diag == win2) {
                win = true;
            }
            // did we win?
            if (win) {
                // make sure we haven't already visited this from a different spot
                if (!configs.count(getNum(checking))) {
                    ans++;
                    configs.insert(getNum(checking));
                }
                continue;
            }
            // add to queue if not winning
            q.push(toAdd);
        }
    }
    cout << ans << "\n";
    return 0;
}
