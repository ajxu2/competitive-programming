#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double m, n, x; 
    unsigned long long a, b;
    cin >> m >> n >> x;
    a = ceil(m / x);
    b = ceil(n / x);
    cout << a * b;
    
    return 0;
}
