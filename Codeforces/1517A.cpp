// created: 04-23-2021 Fri 09:42 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a;
    cin >> a;
    if (a % 2050 != 0) {
        cout << "-1\n";
        return;
    } else {
        a /= 2050;
        string str = to_string(a);
        int ans = 0;
        for (int i = 0; i < str.length(); i++) {
            ans += (str[i] - '0');
        }
        cout << ans << "\n";
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
