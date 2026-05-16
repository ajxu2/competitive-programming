// created: 05-16-2026 Sat 09:13 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'C')
            ans += min(i, n - 1 - i) + 1;
    cout << ans << '\n';
    return 0;
}
