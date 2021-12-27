// created: 12-21-2021 Tue 07:36 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0];
    }
    sort(a.begin(), a.end());
    // multiset of when each person will finish
    multiset<int> currEnds;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        currEnds.insert(0); 
    }
    for (int i = 0; i < n; i++) {
        // find the person who's finished latest and can start this movie
        auto it = currEnds.upper_bound(a[i][1]);
        if (it == currEnds.begin()) {
            // no one is available
            continue;
        }
        it--;
        currEnds.erase(it);
        // set the new ending point for this person
        currEnds.insert(a[i][0]);
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
