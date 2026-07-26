// created: 07-25-2026 Sat 08:50 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, d; cin >> m >> d;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool watched = false;
        for (int j = 0; j < m; j++)
            if (s[j] == 'G' && abs(j - i) <= d)
                watched = true;
        ans += !watched;
    }
    cout << ans << '\n';
    return 0;
}
