#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    double x, y;
    cin >> x >> y;
    cout << (int)(ceil(x*y/2)) << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
