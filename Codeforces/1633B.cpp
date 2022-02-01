// created: 01-31-2022 Mon 10:16 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int zero = 0, one = 0;
    for (int i = 0; i < (int)(s.length()); i++) {
        if (s[i] == '0') zero++;
        else one++;
    }
    if (zero == one) cout << zero-1 << "\n";
    else cout << min(zero, one) << "\n";
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
