#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] -= ('A' - 'a');
    }
    if (s == "yes") cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
