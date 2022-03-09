// created: 03-08-2022 Tue 09:29 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    multiset<int> diff;
    for (int i = 0; i < n; i++) diff.insert(a[i+1]-a[i]-1);
    int mu = *(diff.begin());
    int l, r; // which ones are contributing to mu
    for (int i = 1; i <= n; i++) {
        if (a[i]-a[i-1]-1 == mu) {
            l = i-1, r = i;
            break;
        }
    }
    int thisMax = mu;
    if (l != 0) {
        diff.erase(diff.find(a[l]-a[l-1]-1));
        diff.erase(diff.find(a[l+1]-a[l]-1));
        diff.insert(a[l+1]-a[l-1]-1);
        int tmp = *(diff.begin());
        for (int i : diff) {
            // split some diff in half
            thisMax = max(thisMax, min((i-1)/2, tmp));
        }
        // ...or move it to the end
        thisMax = max(thisMax, min(d-a[n]-1, tmp));
        diff.erase(diff.find(a[l+1]-a[l-1]-1));
        diff.insert(a[l]-a[l-1]-1);
        diff.insert(a[l+1]-a[l]-1);
    }
    if (r != n) {
        diff.erase(diff.find(a[r]-a[r-1]-1));
        diff.erase(diff.find(a[r+1]-a[r]-1));
        diff.insert(a[r+1]-a[r-1]-1);
        int tmp = *(diff.begin());
        for (int i : diff) {
            // split some diff in half
            thisMax = max(thisMax, min((i-1)/2, tmp));
        }
        // ...or move it to the end
        thisMax = max(thisMax, min(d-a[n]-1, tmp));
        diff.erase(diff.find(a[r+1]-a[r-1]-1));
        diff.insert(a[r]-a[r-1]-1);
        diff.insert(a[r+1]-a[r]-1);
    } else {
        diff.erase(a[n]-a[n-1]-1);
        diff.insert(d-a[n-1]-1);
        thisMax = max(thisMax, *(diff.begin()));
    }
    cout << thisMax << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
