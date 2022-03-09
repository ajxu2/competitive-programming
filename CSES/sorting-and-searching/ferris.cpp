// created: 03-07-2022 Mon 09:55 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int r = n-1, ans = n;
    for (int l = 0; l < n; l++) {
        while (r > l && a[l] + a[r] > x) r--;
        if (r <= l) break;
        ans--; r--;
    }
    cout << ans << "\n";
    return 0;
}
