// created: 04-08-2021 Thu 11:50 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int temp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a[i] = temp - i;
    }
    vector<long long> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = b[i-1] + a[i];
        if (b[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
