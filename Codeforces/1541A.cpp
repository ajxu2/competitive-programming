// created: 06-25-2021 Fri 01:01 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            cout << i+2 << " " << i+1 << " ";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n-3; i += 2) {
            cout << i+2 << " " << i+1 << " ";
        }
        cout << n << " " << n-2 << " " << n-1 << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
