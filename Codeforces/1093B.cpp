// created: 04-20-2021 Tue 09:51 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    set<char> distinct;
    for (int i = 0; i < s.length(); i++) {
        distinct.insert(s[i]);
    }
    if (distinct.size() == 1) {
        cout << "-1\n";
    } else {
        sort(s.begin(), s.end());
        cout << s << "\n";
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
