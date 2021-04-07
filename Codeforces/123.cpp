#include <iostream>
using namespace std;

int fibonacci(int x) {
    int a = 0, b = 1, c;
    for (int i = 0; i < x-1; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int t;
    cin >> t;
    cout << fibonacci(t+2) - 1 << "\n";
    return 0;
}
