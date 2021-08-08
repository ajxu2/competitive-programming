// created: 08-04-2021 Wed 01:14 PM

#include <bits/stdc++.h>
using namespace std;

bool ycomp(const array<int, 2>& a, const array<int, 2>& b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int psum(vector<vector<int>>& p, int x1, int y1, int x2, int y2) {
    return p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
}

int main() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i][0] = i+1;
    }
    sort(a.begin(), a.end(), ycomp);
    for (int i = 0; i < n; i++) {
        a[i][1] = i+1;
    }
    vector<vector<int>> p(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        p[a[i][0]][a[i][1]]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x1 = a[i][0], y1 = a[i][1], x2 = a[j][0], y2 = a[j][1];
            long long possibilities = psum(p, 1, y1, min(x1, x2), y2);
            possibilities *= psum(p, max(x1, x2), y1, n, y2);
            ans += possibilities;
        }
    }
    ans += n+1;
    cout << ans << "\n";
    return 0;
}
