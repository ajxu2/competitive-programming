// created: 01-31-2022 Mon 10:14 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a;
    cin >> a;
    if (a % 10 >= a % 7) {
        a -= (a % 7);
    } else {
        a += (7 - a % 7);
    }
    cout << a << "\n";
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
