#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> s;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        s.insert(temp);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (s.count(temp)) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
