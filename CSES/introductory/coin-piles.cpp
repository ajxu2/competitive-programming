// created: 03-03-2022 Fri 2:21 PM
 
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b; cin >> a >> b;
    int x = 2*b-a, y = 2*a-b;
    if (x >= 0 && y >= 0 && x % 3 == 0 && y % 3 == 0) cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
