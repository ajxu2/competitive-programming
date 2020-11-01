#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n, ans = 0, temp, loc;
    cin >> n;
    vector<vector<int> > swaps(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            swaps[i].push_back(temp);
        }
    }
    for (int i = 1; i <= 3; i++) {
        int points = 0;
        loc = i;
        for (int j = 0; j < n; j++) {
            if (swaps[j][0] == loc) {
                loc = swaps[j][1];
            } else if (swaps[j][1] == loc) {
                loc = swaps[j][0];
            }
            if (swaps[j][2] == loc) {
                points++;
            }
        }
        ans = max(ans, points);
    }
    cout << ans << "\n";
    return 0;
}
