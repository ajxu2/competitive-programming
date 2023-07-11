// created: 07-11-2023 Tue 10:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1\n"; return;
    } else if (n == 2) {
        cout << "1 2\n"; return;
    } else if (n == 3) {
        cout << "2 1 3\n"; return;
    }
    V<int> ans(n, -1);
    ans[0] = 2; ans[1] = n; ans[n/2] = 1;
    int cnt = n-1;
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = cnt; cnt--;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
