// created: 01-16-2022 Sun 08:38 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> sums(n-1);
    bool has2 = false;
    for (int i = 0; i < n-1; i++) {
        sums[i] = s[i] - '0' + s[i+1] - '0';
        if (sums[i] >= 10) has2 = true;
    }
    if (has2) {
        for (int i = n-2; i >= 0; i--) {
            if (sums[i] >= 10) {
                string tmp = to_string(sums[i]);
                s[i] = tmp[0]; s[i+1] = tmp[1];
                break;
            }
        }
    } else {
        s[0] = sums[0] + '0';
        s.erase(next(s.begin()));
    }
    cout << s << "\n";
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
