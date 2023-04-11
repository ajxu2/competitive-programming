// created: 04-09-2023 Sun 10:02 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<V<int>> ans(2, V<int>(n));
    for (int i = 1; i < n; i += 2) ans[0][i] = i+1;
    for (int i = n-2; i >= 0; i -= 2) ans[0][i] = 2*n-i;
    for (int i = n-2; i >= 0; i -= 2) ans[1][i] = n-1-i;
    for (int i = 1; i < n; i += 2) ans[1][i] = i+n;
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cout << ans[i][j] << " \n"[j == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
