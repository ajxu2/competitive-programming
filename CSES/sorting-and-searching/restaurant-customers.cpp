#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> times(2*n);
    for (int i = 0; i < 2*n; i+=2) {
        cin >> times[i].first >> times[i+1].first;
        times[i].second = 1;
        times[i+1].second = -1;
    }
    sort(times.begin(), times.end());
    int ans = 0;
    int val = 0;
    for (auto& i: times) {
        val += i.second;
        ans = max(ans, val);
    }
    cout << ans << "\n";
    return 0;
}
