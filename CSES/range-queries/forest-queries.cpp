// created: 04-27-2021 Tue 10:43 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n+1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            a[i].push_back(0);
        }
    }
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j-1] == '.') {
                a[i][j] = 0;
            } else {
                a[i][j] = 1;
            }
        }
    }
    vector<vector<int>> p(n+1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            p[i].push_back(0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << p[c][d] - p[a-1][d] - p[c][b-1] + p[a-1][b-1] << "\n";
    }
    return 0;
}
