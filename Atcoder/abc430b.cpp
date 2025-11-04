// created: 11-01-2025 Sat 08:02 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<bool>> a(n, V<bool>(n, false));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] == '#';
    }
    set<pair<ll, ll>> patterns;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            ll one = 0, two = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (k <= m / 2)
                        (one <<= 1) += a[i + k][j + l];
                    else
                        (two <<= 1) += a[i + k][j + l];
                }
            }
            patterns.insert({one, two});
        }
    }
    cout << patterns.size() << '\n';
    return 0;
}
