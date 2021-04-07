#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, t1, t2, t3;
    cin >> n >> t1 >> t2;
    for (int i = 0; i < n-2; i++) {
        cin >> t3;
    }
    if (t1 + t2 <= t3) {
        cout << "1 2 " << n << "\n";
    } else {
        cout << "-1\n";
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
