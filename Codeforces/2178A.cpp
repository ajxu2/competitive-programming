// created: 12-27-2025 Sat 08:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    string s; cin >> s;
    int cnt_y = 0;
    for (char i : s)
        if (i == 'Y')
            cnt_y++;
    cout << (cnt_y <= 1 ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
