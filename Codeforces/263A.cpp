#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t, x = 1, row, col;
    cin >> t;
    while (t == 0) {
        cin >> t;
        ++x;
    }
    row = (x-1)/5;
    col = (x-1)%5;
    cout << abs(row-2) + abs(col-2) << "\n";
}
