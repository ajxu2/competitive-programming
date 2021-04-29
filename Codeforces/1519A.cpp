// created: 04-29-2021 Thu 09:35 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, b, d;
    cin >> r >> b >> d;
    if (r < b) {
        if ((r+b-1)/r <= (d+1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if ((r+b-1)/b <= (d+1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
