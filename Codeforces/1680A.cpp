// created: 05-13-2022 Fri 05:45 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a) cout << a+c << "\n";
    else if (a <= c) cout << c << "\n";
    else cout << a << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
