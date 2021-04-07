#include <iostream>
using namespace std;

int main() {
    int n, k, t, s, a = 0;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> t;
        if (t <= 0) {
            cout << a << "\n";
            return 0;
        }
        ++a;
    }
    s = t;
    while (s == t && a != n && t > 0) {
        cin >> t;
        ++a;
    }
    if (t <= 0) {
        cout << a-1 << "\n";
    } else if (s != t) {
        cout << a-1 << "\n";
    } else {
        cout << a << "\n"; 
    }
    return 0;
}
