// created: 03-08-2022 Tue 08:32 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    char c; cin >> c;
    bool works = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c && i % 2 == 0) works = true;
    }
    if (works) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
