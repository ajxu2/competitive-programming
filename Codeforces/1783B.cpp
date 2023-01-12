// created: 01-08-2023 Sun 08:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    // no idea if this works
    int n; cin >> n;
    V<V<int>> a(n, V<int>(n));
    int l = 1, r = n*n;
    for (int i = 0; i <= 2*(n-1); i++) {
        for (int j = min(i, n-1); i - j < n && j >= 0; j--) {
            if (i % 2 == 0) {
                a[i-j][j] = l; l++;
            } else {
                a[i-j][j] = r; r--;
            }
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << a[i][j] << " \n"[j == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
