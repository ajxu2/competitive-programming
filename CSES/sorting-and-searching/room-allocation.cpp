#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i][0] >> times[i][1];
        times[i][2] = i;
    }
    sort(times.begin(), times.end());
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    int ans = 1;
    vector<int> rooms(n);
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            pq.push({times[i][1], 1, times[i][2]});
            rooms[times[i][2]] = 1;
        } else {
            if (times[i][0] > pq.top()[0]) {
                int temp = pq.top()[1];
                pq.pop();
                pq.push({times[i][1], temp, times[i][2]});
                rooms[times[i][2]] = temp;
                ans = max(ans, temp);
            } else {
                pq.push({times[i][1], (int)pq.size()+1, times[i][2]});
                rooms[times[i][2]] = (int)pq.size();
                ans = max(ans, (int)pq.size());
            }
        }
    }
    cout << ans << "\n";
    for (auto& i : rooms) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
