#include <iostream>
using namespace std;

int fib(int n) {
    if (n<=2) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int x;
    string ans = "";
    cin >> x;
    for (int i = 0; i < x; i++) {
        ans = ans + "o";
    }
    for (int i = 1; fib(i) <= x; i++) {
        ans[fib(i)-1] = 'O';
    }
    cout << ans << "\n";
    return 0;
}
