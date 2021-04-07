#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x == 2 || x % 2 == 1) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    
    return 0;
}
