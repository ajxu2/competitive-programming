// created: 04-29-2021 Thu 09:42 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m - 1 == k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
