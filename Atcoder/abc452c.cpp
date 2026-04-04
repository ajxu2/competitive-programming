// created: 04-04-2026 Sat 09:00 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int m; cin >> m;
    V<string> s(m);
    for (string& i : s)
        cin >> i;
    V<array<bool, 26>> c(n);
    for (int i = 0; i < n; i++) {
        for (string& j : s)
            if (ssize(j) == a[i])
                c[i][j[b[i] - 1] - 'a'] = true;
    }
    for (string& i : s) {
        bool good = ssize(i) == n;
        if (good) {
            for (int j = 0; j < n; j++)
                good &= c[j][i[j] - 'a'];
        }
        cout << (good ? "Yes" : "No") << '\n';
    }
    return 0;
}
