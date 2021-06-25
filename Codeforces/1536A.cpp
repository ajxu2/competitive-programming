// created: 06-06-2021 Sun 09:35 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    bool yn = true;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < 0) {
            yn = false;
        }
    }
    if (!yn) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n300\n";
    for (int i = 0; i < 300; i++) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
