#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if ((n % 2020) <= (n / 2020)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
