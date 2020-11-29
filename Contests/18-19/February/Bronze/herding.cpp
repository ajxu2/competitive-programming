#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> locs(3);
    cin >> locs[0] >> locs[1] >> locs[2];
    sort(locs.begin(), locs.end());
    int ansmin, ansmax;
    int gap1 = locs[1] - locs[0];
    int gap2 = locs[2] - locs[1];
    if (gap1 == 1 && gap2 == 1) {
        ansmin = 0;
    } else if (gap1 == 2 || gap2 == 2) {
        ansmin = 1;
    } else {
        ansmin = 2;
    }
    int largestGap = 0;
    largestGap = max(largestGap, locs[1] - locs[0]);
    largestGap = max(largestGap, locs[2] - locs[1]);
    ansmax = largestGap - 1;
    cout << ansmin << "\n" << ansmax << "\n";
    return 0;
}
