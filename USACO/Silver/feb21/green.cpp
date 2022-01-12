// created: 01-09-2022 Sun 02:55 PM

#include <bits/stdc++.h>
using namespace std;

long long getAns(vector<vector<int>>& a, int n, int m) {
    // get the number of subgrids with minimum value greater than m
    // avoid anything less than or equal to m
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] <= m) b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    // 1D prefix sums on the columns
    vector<vector<int>> p(n+1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        p[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = p[i-1][j] + b[i-1][j];
        }
    }
    // get the number of subgrids with all zeroes
    long long res = 0;
    // loop through all upper and lower bounds for the subgrids
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            // use the prefix sums
            vector<int> tmp;
            for (int k = 0; k < n; k++) {
                tmp.push_back(p[j][k]-p[i-1][k]);
            }
            // calculate number of subgrids
            int tmp2 = 0;
            for (int k = 0; k < n; k++) {
                if (tmp[k] == 0) {
                    // part of a string of 0s
                    tmp2++;
                    res += tmp2;
                } else {
                    // end string of 0s
                    tmp2 = 0;
                }
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << getAns(a, n, 99) - getAns(a, n, 100) << "\n";
    return 0;
}
