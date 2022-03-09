// created: 03-08-2022 Tue 08:39 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, a; cin >> l >> r >> a;
    int x = r - (((r%a)+1)%a);
    if (x < l) cout << r/a+r%a << "\n";
    else cout << x/a+x%a << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
