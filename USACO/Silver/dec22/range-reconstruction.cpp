// created: 12-29-2022 Thu 05:06 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<int>> a(n, V<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> a[i][j];
        }
    }
    V<int> b(n); b[0] = 0;
    for (int i = 1; i < n; i++) {
        // test +
        b[i] = b[i-1] + a[i-1][i];
        bool ok = true;
        int mx = b[i], mn = b[i];
        for (int j = i-1; j >= 0; j--) {
            mx = max(mx, b[j]); mn = min(mn, b[j]);
            ok &= (mx - mn == a[j][i]);
        }
        if (!ok) b[i] = b[i-1] - a[i-1][i];
    }
    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n-1];
    return 0;
}
