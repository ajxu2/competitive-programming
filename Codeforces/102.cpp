#include <iostream>
using namespace std;

int gcd(int x, int y) {
    int swap;
    if (x < y) {
        swap = x;
        x = y;
        y = swap;
    }
    if (y == 0) {
        return x;
    }
    return gcd(y, x-y);
}

int main() {
    int t, ans = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        if (gcd(i, t) == 1) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
