// created: 05-13-2025 Tue 02:24 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<short>> a(n, V<short>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j] - 'A';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            short avoid1 = i == 0 ? -1 : a[i-1][j];
            short avoid2 = j == 0 ? -1 : a[i][j-1];
            do {
                a[i][j] = (a[i][j] + 1) & 3;
            } while (a[i][j] == avoid1 || a[i][j] == avoid2);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << (char)(a[i][j] + 'A');
        cout << '\n';
    }
    return 0;
}
