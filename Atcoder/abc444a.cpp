// created: 02-07-2026 Sat 07:45 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    if (s[0] == s[1] && s[1] == s[2])
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
