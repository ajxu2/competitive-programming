// created: 11-01-2025 Sat 08:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

V<int> z_algo(string s) {
    int n = ssize(s);
    V<int> z(n, 0);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        if (r > i)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

void solve() {
    string s, t; cin >> s >> t;
    string orz = t;
    orz.push_back('#');
    orz += s;
    orz += s;
    V<int> z = z_algo(orz);
    int n = ssize(s);
    for (int i = n + 1; i < ssize(orz); i++) {
        if (z[i] == n) {
            cout << i - n - 1 << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
