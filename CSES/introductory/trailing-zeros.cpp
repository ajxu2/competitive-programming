// created: 03-03-2022 Fri 2:18 PM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 5; ; i *= 5) {
        if (n/i == 0) break;
        ans += n/i;
    }
    cout << ans << "\n";
    return 0;
}
