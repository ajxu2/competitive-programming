// created: 07-25-2026 Sat 08:44 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i, seen = 0;
        while (l >= 0 && r < n && seen <= 1) {
            if (s[l] != s[r])
                seen++;
            if (seen <= 1)
                ans++;
            l--, r++;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int l = i, r = i + 1, seen = 0;
        while (l >= 0 && r < n && seen <= 1) {
            if (s[l] != s[r])
                seen++;
            if (seen <= 1)
                ans++;
            l--, r++;
        }
    }
    cout << ans << '\n';
    return 0;
}
