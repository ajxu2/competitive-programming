// created: 07-07-2024 Sun 09:40 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> a(n, V<int>(m)), b(n, V<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) b[i][j] = s[j] - '0';
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < m; j++) {
            sum1 += a[i][j];
            sum2 += b[i][j];
        }
        ok &= sum1 % 3 == sum2 % 3;
    }
    for (int j = 0; j < m; j++) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += a[i][j];
            sum2 += b[i][j];
        }
        ok &= sum1 % 3 == sum2 % 3;
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
