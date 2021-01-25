#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    int ans = 1;
    if (ans >= n) {
        cout << "YES\n";
        return;
    }
    while (w % 2 == 0) {
        w /= 2;
        ans *= 2;
        if (ans >= n) {
            cout << "YES\n";
            return;
        }
    }
    while (h % 2 == 0) {
        h /= 2;
        ans *= 2;
        if (ans >= n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
