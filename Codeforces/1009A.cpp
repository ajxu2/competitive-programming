// created: 07-05-2022 Tue 10:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<int> c(n), a(m);
    for (int& i : c) cin >> i;
    for (int& i : a) cin >> i;
    int ptr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (ptr != m && a[ptr] >= c[i]) {
            ans++;
            ptr++;
        }
    }
    cout << ans << "\n";
    return 0;
}
