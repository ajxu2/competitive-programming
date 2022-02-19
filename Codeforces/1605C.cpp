// created: 02-16-2022 Wed 10:56 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    const int x = string::npos;
    int ans = -1;
    if (s.find("aa") != x) ans = 2;
    else if (s.find("aba") != x) ans = 3;
    else if (s.find("aca") != x) ans = 3;
    else if (s.find("abca") != x) ans = 4;
    else if (s.find("acba") != x) ans = 4;
    else if (s.find("abbacca") != x) ans = 7;
    else if (s.find("accabba") != x) ans = 7;
    cout << ans << "\n";
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
