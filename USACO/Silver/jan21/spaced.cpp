// created: 2021-1-14 at 8:50 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> rows(n);
    // rows alternating
    for (int i = 0; i < n; i++) {
        int tmp1 = 0, tmp2 = 0;
        for (int j = 0; j < n; j += 2) {
            tmp1 += a[i][j];
        }
        for (int j = 1; j < n; j += 2) {
            tmp2 += a[i][j];
        }
        rows[i] = max(tmp1, tmp2);
    }
    vector<int> cols(n);
    // columns alternating
    for (int i = 0; i < n; i++) {
        int tmp1 = 0, tmp2 = 0;
        for (int j = 0; j < n; j += 2) {
            tmp1 += a[j][i];
        }
        for (int j = 1; j < n; j += 2) {
            tmp2 += a[j][i];
        }
        cols[i] = max(tmp1, tmp2);
    }
    // take max of sums
    int tmp1 = 0, tmp2 = 0;
    for (int i = 0; i < n; i++) {
        tmp1 += rows[i];
    }
    for (int i = 0; i < n; i++) {
        tmp2 += cols[i];
    }
    cout << max(tmp1, tmp2) << "\n";
    return 0;
}