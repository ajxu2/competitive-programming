#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
        ans %= 1000000007;
    }
    cout << ans << "\n";
    return 0;
}
