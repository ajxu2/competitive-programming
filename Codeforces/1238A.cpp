#include <iostream>
using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;
    if ((x - y) != 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
