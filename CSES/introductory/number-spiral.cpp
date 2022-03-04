// created: 03-03-2022 Thu 12:12 PM
 
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    long long y, x; cin >> y >> x;
    if (x < y) {
        if (y % 2 == 0) cout << y*y-x+1 << "\n";
        else cout << (y-1)*(y-1)+x << "\n";
    } else {
        if (x % 2 == 0) cout << (x-1)*(x-1)+y << "\n";
        else cout << x*x-y+1 << "\n";
    }
}
 
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
