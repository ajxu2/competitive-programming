// created: 08-01-2026 Sat 12:13 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool good = s[i] == 'x';
        good &= i == 0 || s[i - 1] == 'x';
        good &= i == n - 1 || s[i + 1] == 'x';
        ans += good;
    }
    cout << ans << '\n';
    return 0;
}
