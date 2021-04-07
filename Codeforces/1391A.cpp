#include <iostream>
using namespace std;
void solve() {
    int x;
    cin >> x;
    for (int i = 1; i <= x; i++) {
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
}
