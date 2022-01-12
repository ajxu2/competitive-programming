// created: 01-09-2022 Sun 12:14 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // adjust the years to be years Bessie can portal to
    for (int i = 0; i < n; i++) {
        a[i] += 12 - (a[i] % 12);
    }
    // number of years Bessie can "skip"
    vector<int> skip(n);
    skip[0] = a[0] - 12;
    for (int i = 1; i < n; i++) {
        skip[i] = a[i] - a[i-1] - 12;
        if (skip[i] == -12) {
            // why do a skip back when you could just not
            skip[i] = 0;
        }
    }
    // -12 to account for the fact that ancestor must actually be visited
    // skip the greatest number of years
    sort(skip.begin(), skip.end(), greater<int>());
    // strategy: go back to beginning and skip the greatest number of years
    int toSkip = 0;
    for (int i = 0; i < k-1; i++) {
        toSkip += skip[i];
    }
    cout << a.back() - toSkip << "\n";
    return 0;
}
