// created: 02-26-2022 Sat 01:41 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> stations(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        // let's redefine the candies by the distance to the next station
        b -= a;
        if (b < 0) b += n;
        stations[a].push_back(b);
    }
    // let's say you started from this station
    // how long would it take to move all the candies from this station
    // to the correct station?
    for (int i = 1; i <= n; i++) {
        sort(stations[i].begin(), stations[i].end(), greater<int>());
    }
    vector<int> start(n+1);
    for (int i = 1; i <= n; i++) {
        if (stations[i].size() == 0) start[i] = 0;
        else start[i] = (stations[i].size()-1)*n+stations[i].back();
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (start[(i+j-1)%n+1] != 0) ans = max(ans, j+start[(i+j-1)%n+1]);
        }
        cout << ans << " \n"[i == n];
    }
    return 0;
}
