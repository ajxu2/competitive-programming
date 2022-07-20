#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<bool> solved(26, false);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!solved[s[i]-'A']) ans++;
        solved[s[i]-'A'] = true;
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
