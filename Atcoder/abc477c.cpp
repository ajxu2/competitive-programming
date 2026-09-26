// created: 09-26-2026 Sat 09:05 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; string s, t; cin >> q >> s >> t;
    int n = ssize(s), m = ssize(t);
    if (n < m) {
        while (q--)
            cout << "No\n";
        return 0;
    }
    V<int> found(n - m + 1, 0);
    for (int i = 0; i <= n - m; i++)
        if (s.substr(i, m) == t)
            found[i] = 1;
    V<int> p(n - m + 2, 0);
    for (int i = 1; i < n - m + 2; i++)
        p[i] = p[i - 1] + found[i - 1];
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        if (r - l + 1 < m) {
            cout << "No\n";
        } else {
            r -= m - 1;
            // search found[l, r] for 1
            cout << (p[r + 1] - p[l] > 0 ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}
