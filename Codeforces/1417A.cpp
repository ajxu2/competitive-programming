#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            ans += (k-a[i])/a[0];
        }
        cout << ans << "\n";
    }
    return 0;
}
