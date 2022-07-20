#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    set<string> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 1; j < a[i].length(); j++) {
            if (s.find(a[i].substr(0, j)) != s.end() && s.find(a[i].substr(j)) != s.end()) {
                ok = true; break;
            }
        }
        if (ok) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
