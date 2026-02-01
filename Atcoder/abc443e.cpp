// created: 01-31-2026 Sat 12:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, c; cin >> n >> c; c--;
    V<string> a(n);
    for (string& i : a)
        cin >> i;
    V<V<bool>> reachable(n, V<bool>(n, false));
    reachable[n - 1][c] = true;
    V<bool> seen_wall(n, false);
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#' && !seen_wall[j]) {
                seen_wall[j] = true;
                if (reachable[i][j]) {
                    for (int k = i - 1; k >= 0; k--)
                        reachable[k][j] = true;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (!reachable[i][j])
                continue;
            for (int k = max(j - 1, 0); k <= min(j + 1, n - 1); k++) {
                // a[i][j] -> a[i - 1][k]
                if (a[i - 1][k] == '.' || !seen_wall[k])
                    reachable[i - 1][k] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << reachable[0][i];
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
