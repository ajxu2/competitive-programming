// created: 06-27-2024 Thu 01:13 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    string s, t; cin >> s >> t;
    int n = ssize(s), m = ssize(t);
    int ans = n + m;
    for (int i = 0; i < m; i++) {
        int sptr = 0, tptr = i;
        while (sptr < n && tptr < m) {
            while (sptr < n && s[sptr] != t[tptr]) sptr++;
            if (sptr < n) {
                tptr++; sptr++;
            }
        }
        ans = min(ans, n + m - (tptr - i));
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
