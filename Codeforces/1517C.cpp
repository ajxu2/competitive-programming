// created: 01-14-2022 Fri 11:37 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // the board
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i][i];
    }
    for (int i = 0; i < n; i++) {
        int tmp = a[i][i], x = i, y = i;
        for (int j = 0; j < tmp-1; j++) {
            // if you can go left, go left
            // or if you can go down, go down
            if (y != 0 && a[x][y-1] == 0) {
                y--;
                a[x][y] = tmp;
            } else if (x != n-1 && a[x+1][y] == 0) {
                x++;
                a[x][y] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << " \n"[j == i];
        }
    }
    return 0;
}
