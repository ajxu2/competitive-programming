// created: 03-06-2022 Sun 09:04 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        // can Elsie make i class periods?
        if (sum % i != 0) continue;
        int desired = sum / i, tmp = 0, thisAns = 0;
        bool works = true;
        for (int j = 0; j < n; j++) {
            tmp += a[j];
            if (tmp == desired) tmp = 0;
            else if (tmp > desired) works = false;
            else thisAns++;
        }
        if (works) ans = min(thisAns, ans);
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
