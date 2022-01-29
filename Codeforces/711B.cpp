// created: 01-29-2022 Sat 12:14 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // i hate edge cases :suffering:
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    vector<vector<long long>> a(n, vector<long long>(n));
    array<int, 2> pt; // the coordinates of the point
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) pt = {i, j};
        }
    }
    // take the sum of this row
    long long tmp1 = 0;
    for (int i = 0; i < n; i++) {
        tmp1 += a[pt[0]][i];
    }
    // take the sum of the next row to determine what the number should be
    long long tmp2 = 0;
    for (int i = 0; i < n; i++) {
        tmp2 += a[(pt[0]+1)%n][i];
    }
    // replace number
    a[pt[0]][pt[1]] = tmp2 - tmp1;
    // check if this is a magic square
    bool magic = true;
    // first, make sure that the replaced number is positive
    if (a[pt[0]][pt[1]] <= 0) magic = false;
    long long tmp3 = 0;
    // rows
    for (int i = 0; i < n; i++) {
        tmp3 = 0;
        for (int j = 0; j < n; j++) {
            tmp3 += a[i][j];
        }
        if (tmp3 != tmp2) {
            magic = false;
            break;
        }
    }
    // columns
    for (int i = 0; i < n; i++) {
        tmp3 = 0;
        for (int j = 0; j < n; j++) {
            tmp3 += a[j][i];
        }
        if (tmp3 != tmp2) {
            magic = false;
            break;
        }
    }
    // diag 1
    tmp3 = 0;
    for (int i = 0; i < n; i++) {
        tmp3 += a[i][i];
    }
    if (tmp3 != tmp2) magic = false;
    // diag 2
    tmp3 = 0;
    for (int i = 0; i < n; i++) {
        tmp3 += a[i][n-i-1];
    }
    if (tmp3 != tmp2) magic = false;
    if (magic) cout << a[pt[0]][pt[1]] << "\n";
    else cout << "-1\n";
    return 0;
}
