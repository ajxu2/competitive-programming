// created: 05-22-2022 Sun 09:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s.push_back(' ');
    char cur = ' '; int ans;
    int beg = 0, end = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == cur) end++;
        else {
            if (beg <= n/2 && n/2 <= end) ans = end - beg + 1;
            beg = i, end = i, cur = s[i];
        }
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
