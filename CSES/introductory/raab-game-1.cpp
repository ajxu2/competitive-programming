// created: 05-13-2025 Tue 01:25 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO\n";
    } else if (a == 0 && b == 0) {
        cout << "YES\n";
        for (int e = 0; e < 2; e++)
            for (int i = 1; i <= n; i++)
                cout << i << " \n"[i == n];
    } else if (a == 0 || b == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << i << " \n"[i == n];
        for (int i = 1; i <= n; i++) {
            if (i <= a + b)
                cout << (i + a - 1) % (a + b) + 1;
            else
                cout << i;
            cout << " \n"[i == n];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
