// created: 11-26-2022 Sat 11:17 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    vector<int> p(n);
    bool ok = true;
    for (int i = 1; i < n; i += 2) {
        cin >> p[i];
        if (s.count(p[i])) s.erase(p[i]);
        else ok = false;
    }
    if (!ok) {
        cout << "-1\n";
        return;
    }
    // WORK FROM BACK TO FRONT BOZO
    for (int i = n-2; i >= 0; i -= 2) {
        auto it = s.lower_bound(p[i+1]);
        if (it == s.begin()) {
            cout << "-1\n";
            return;
        }
        it--;
        p[i] = *it;
        s.erase(it);
    }
    for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n-1];
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
