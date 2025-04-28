// created: 04-27-2025 Sun 08:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string t, u; cin >> t >> u;
    int n = ssize(t), m = ssize(u);
    for (int i = 0; i <= n - m; i++) {
        string s = t.substr(i, m);
        bool ok = true;
        for (int j = 0; j < m; j++)
            ok &= (s[j] == '?' || s[j] == u[j]);
        if (ok) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
