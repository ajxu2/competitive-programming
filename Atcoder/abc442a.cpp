// created: 01-24-2026 Sat 07:06 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int ans = 0;
    for (char i : s)
        ans += (i == 'i' || i == 'j');
    cout << ans << '\n';
    return 0;
}
